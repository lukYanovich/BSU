package com.company;

import com.company.others.Func;

import javax.xml.stream.XMLStreamException;
import java.io.*;
import java.net.Socket;
import java.util.Scanner;


public class Client {

    public static void main(String[] args) throws Exception {
        // write your code here

        try (
                Socket socket = new Socket("localhost", 3000);
                ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
                ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
                Scanner in = new Scanner(System.in)) {

            while (true) {

                Func.writeToXML(oos, in.nextLine());
                oos.flush();

                try {
                    System.out.println(Func.readFromXML(ois));
                } catch (XMLStreamException e) {
                    e.printStackTrace();
                }
            }
        } catch (Exception e) {
            System.err.println(e);
        }
    }
}
