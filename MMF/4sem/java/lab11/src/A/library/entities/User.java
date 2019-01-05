package A.library.entities;

import java.util.List;
import java.util.Scanner;

public class User extends Thread {
    private String _name;
    private List<Book> _arr_books;
    private Scanner in;


    public User() {
        StringBuilder message = new StringBuilder();
        String command1 = "t name - взять книгу";
        String command2 = "r name - вернуть книгу";
        String command_exit = "exit - завершить программу";
        message.append(command1).append("\n");
        message.append(command2).append("\n");
        message.append(command_exit).append("\n");
        System.out.println(message);

        System.out.print("введите ваше имя: ");
        in = new Scanner(System.in);
        this._name = in.nextLine();
    }


    @Override
    public void run() {
        while (!isInterrupted()) {
            String str = in.nextLine();
            if (str.equals("exit"))
                exit();
            else {
                try {
                    char mode = str.charAt(0);
                    String name_book = str.substring(2);
                    switch (mode) {
                        case 't':
                            //поиск и дать
                            break;
                        case 'r':
                            //вернуть
                            break;
                        default:
                            throw new Exception("некорректный ввод");
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }


    private void exit() {
        this.interrupt();
        in.close();
    }
}
