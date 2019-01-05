package server;


import main.my.Exchange;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;


public class Server extends Thread {
    private ServerSocket _server;
    private List<Connection> _connections;
    private String _server_name;


    public Server() {
        this._connections = Collections.synchronizedList(new ArrayList<>());
        this._server_name = Exchange.server_name;
        try {
            this._server = new ServerSocket(Exchange.port);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    //для каждого подключения создаётся объект Connection и добавляет его в список подключений.
    @Override
    public void run() {
        try {
            while (true) {
                /*
                server.accept() указывает серверу ожидать подключения. Как только какой-то клиент
                подключится к серверу, метод вернёт объект Socket, связанный с этим подключением.
                */
                Socket socket = this._server.accept();
                Connection connection = new Connection(socket);
                this._connections.add(connection);
                connection.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            _close_all();
        }
    }


    private void _close_all() {
        try {
            this._server.close();
            synchronized (this._connections) {
                for (Connection connection : this._connections) {
                    connection._close();
                }
            }
        } catch (IOException e) {
            System.err.println("потоки не закрыты");
            e.printStackTrace();
        }
    }


    private class Connection extends Thread {
        private Socket _socket;
        private BufferedReader _in;
        private PrintWriter _out;
        private String _name = "";


        Connection(Socket socket) {
            this._socket = socket;
            try {
                this._in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                this._out = new PrintWriter(socket.getOutputStream(), true);
            } catch (IOException e) {
                e.printStackTrace();
                _close();
            }
        }


        private void _send_to_everything_connections(String login, String message) {
            //шаблон сообщения
            String str = login + Exchange.separator_between_nickname_and_message + message;
            synchronized (_connections) {
                for (Connection connection : _connections) {
                    connection._out.println(str);
                }
            }
        }


        private void _authorization() throws Exception {
            this._name = this._in.readLine();
            for (Connection connection : _connections) {
                //если имя уже занято, обрываем соединение
                if (connection._name.equals(this._name) && this!=connection) {
                    this._out.println("close");
                    throw new Exception("логин занят");
                }
            }
            this._out.println("ok");
        }


        @Override
        public void run() {
            try {
                _authorization();
                String system_message = "user \"" + this._name + "\" cames now";
                _send_to_everything_connections(Server.this._server_name, system_message);
                while (true) {
                    system_message = _in.readLine();
                    if (system_message.equals(Exchange.disconnect_client_flag))
                        break;
                    _send_to_everything_connections(this._name, system_message);
                }
                system_message = "user \"" + this._name + "\" has left";
                _send_to_everything_connections(Server.this._server_name, system_message);
            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                _close();
            }
        }


        private void _close() {
            try {
                this._in.close();
                this._out.close();
                this._socket.close();
                _connections.remove(this);
                if (_connections.size() == 0) {
                    Server.this._close_all();
                }
            } catch (IOException e) {
                System.err.println("подключение не закрыто");
                e.printStackTrace();
            }
        }
    }
}
