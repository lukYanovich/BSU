package com.company;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        try (
                Socket socket = new Socket("localhost", 3000);
                ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
                ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
                Scanner in = new Scanner(System.in)) {

            while (true) {

                oos.writeUTF(in.nextLine());
                oos.flush();
                System.out.println(ois.readUTF());
            }
        } catch (Exception e) {
            System.err.println(e);
        }
    }
}
