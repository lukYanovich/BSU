package A.start;

import java.util.Scanner;

public class Main extends Thread {
    public static void main(String[] args) {
        /*
        if (args.length == 0)
            (new User()).start();
        else
            (new Library()).start();
            */
        StringBuilder message = new StringBuilder();
        String command1 = "t name - взять книгу";
        String command2 = "r name - вернуть книгу";
        String command_exit = "exit - завершить программу";
        message.append(command1).append("\n");
        message.append(command2).append("\n");
        message.append(command_exit).append("\n");
        System.err.println(message);
        try {
            sleep(0);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.print("введите ваше имя: ");
        Scanner in = new Scanner(System.in);
        //this._name = in.nextLine();
    }
}
