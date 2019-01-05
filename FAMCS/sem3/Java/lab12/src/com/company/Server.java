package com.company;

import com.company.others.Func;

import javax.xml.stream.XMLStreamException;
import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;
import java.util.concurrent.*;


public class Server {

    public static void main(String[] args) throws Exception {
        // write your code here

        try (ServerSocket server = new ServerSocket(3000, 0, InetAddress.getByName("localhost"))) {

            ExecutorService tp = Executors.newFixedThreadPool(2);
            Semaphore semaphore = new Semaphore(2);

            while (true) {

                semaphore.acquire();
                Socket socket = server.accept();

                tp.execute(() -> {

                    try (Socket accept = socket) {
                        serve(accept);
                    } catch (Exception e) {
                        System.err.println(e);
                        e.printStackTrace();
                    } finally {
                        semaphore.release();
                    }
                });
            }
        } catch (Throwable e) {
            System.err.println(e);
            e.printStackTrace();
        }
    }


    private static void serve(final Socket socket) throws Exception {
        try (
                ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
                ObjectInputStream ois = new ObjectInputStream(socket.getInputStream())) {

            String temp = "";

            try {
                temp = Func.readFromXML(ois);
            } catch (XMLStreamException e) {
                e.printStackTrace();
            }

            while (temp.compareTo("exit") != 0) {

                Process process = Runtime.getRuntime().exec("cmd.exe /c " + temp);
                temp = "";

                try (Scanner in = new Scanner(process.getInputStream())) {

                    while (in.hasNextLine())
                        temp += in.nextLine() + "\n";
                } catch (Exception e) {
                    System.err.println(e);
                    e.printStackTrace();
                }

                Func.writeToXML(oos, temp);
                oos.flush();
                temp = Func.readFromXML(ois);
            }
        } catch (IOException e) {
            System.err.println(e);
            e.printStackTrace();
        }
    }
}
