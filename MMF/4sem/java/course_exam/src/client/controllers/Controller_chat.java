package client.controllers;


import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import main.my.Exchange;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;


public class Controller_chat extends Thread {
    @FXML
    private TextArea _messages_all;
    @FXML
    private TextField _message;
    @FXML
    private Button _btn_send;
    private String _user_name;
    private BufferedReader _in;
    private PrintWriter _out;
    private Socket _socket;

    private static final String _system_message_beg = "</--------";
    private static final String _system_message_end = "--------\\>";
    private boolean _hasError;


    @FXML
    public void initialize() {
        this._user_name = "";
        this._hasError = false;
        this._btn_send.setFocusTraversable(false);
        this._message.setFocusTraversable(true);
    }


    void set_user_name(String login) {
        this._user_name = login;
    }


    @Override
    public void run() {
        try {
            this._socket = new Socket(Exchange.ip, Exchange.port);
            this._in = new BufferedReader(new InputStreamReader(_socket.getInputStream()));
            this._out = new PrintWriter(_socket.getOutputStream(), true);
            //отправляем серверу логин из родительского окна
            this._out.println(_user_name);
            //ответ от сервера можно ли начать работу
            if (!this._in.readLine().equals("ok")) {
                String error_message = "это имя уже используется в сети.\n\nвероятно, это не ваш логин. создайте новый";
                this._messages_all.setStyle("-fx-text-fill: red");
                this._messages_all.setText(error_message);
                this.interrupt();
                this._hasError = true;
            }
            //получение данных с сервер
            while (!isInterrupted()) {
                String str = _in.readLine();
                String[] message = str.split(Exchange.separator_between_nickname_and_message);
                if (message[0].equals(Exchange.server_name)) {
                    //шаблон системного сообщения
                    str = Controller_chat._system_message_beg + str + Controller_chat._system_message_end + "\n";
                    this._messages_all.appendText(str);
                } else {
                    str = str + "\n";
                    this._messages_all.appendText(str);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public void send_button_click(ActionEvent actionEvent) {
        if (!this._message.getText().equals("")) {
            //отправка данных на сервер
            _out.println(this._message.getText());
            this._message.clear();
        }
    }


    void close_window() {
        try {
            if (!this._hasError)
                this._out.println(Exchange.disconnect_client_flag);
            this._in.close();
            this._out.close();
            this._socket.close();
        } catch (IOException e) {
            System.err.println("потоки не закрыты");
            e.printStackTrace();
        }
    }
}
