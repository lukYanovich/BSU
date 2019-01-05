package A.library.entities;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Library extends Thread {
    private static List<Book> _arr;
    private static int _count_of_active_libraries=0;
    private static List<User> _list_users;
    private static String _filename = "C:\\Projects\\MMF\\4sem\\java\\lab11\\src\\A\\resources\\list_book.txt";
    private static String _separator = ";";

    private Scanner _in;


    public Library() {
        //проверим семафор на чтение из файла
        if (Library._count_of_active_libraries == 0) {
            Library._arr = Collections.synchronizedList(new ArrayList<>());
            try (BufferedReader in = new BufferedReader(new FileReader(Library._filename))) {
                String str = in.readLine();
                while (str != null) {
                    String[] _book = str.split(Library._separator);
                    Book book = new Book(
                            Integer.parseInt(_book[0]),
                            _book[1],
                            Boolean.parseBoolean(_book[2]));
                    Library._arr.add(book);
                    str = in.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        Library._count_of_active_libraries++;
    }


    @Override
    public void run() {
        while(!isInterrupted()){
            if(_in.nextLine().equals("exit"))
            exit();
        }
    }

    private void exit(){
        this.interrupt();
        _in.close();
        Library._count_of_active_libraries--;
        if(Library._count_of_active_libraries==0) {
            try (BufferedWriter out=new BufferedWriter(new FileWriter(Library._filename))){
                for(Book book: Library._arr){
                    StringBuilder str=new StringBuilder(book._id);
                    str.append(Library._separator);
                    //out.write(str);
                }
            }
            catch (IOException e){
                e.printStackTrace();
            }
        }
    }
}
