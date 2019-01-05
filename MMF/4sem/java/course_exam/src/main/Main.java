package main;


import client.start.Start;
import server.Server;

import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {
    public static void main(String[] args) {
        System.out.println("Запустить программу в режиме сервера или клиента? (S(erver) / C(lient))");
        try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in))) {
            while (true) {
                char answer = Character.toLowerCase(in.readLine().charAt(0));
                if (answer == 's') {
                    Server server = new Server();
                    server.start();
                    break;
                } else if (answer == 'c') {
                    Start.main(args);
                    break;
                } else {
                    System.out.println("Некорректный ввод. Повторите.");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
