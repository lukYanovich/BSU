package com.company;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    private static boolean _is_palindrome(String a, String b) {
        StringBuilder temp = new StringBuilder(b);
        return a.equals(temp.reverse().toString());
    }


    public static void main(String[] args) {
        String filename = "C:\\Projects\\MMF\\4sem\\java\\lab1\\src\\com\\company\\resources\\input.txt";
        List<String> arr = new ArrayList<>();
        try (BufferedReader in = new BufferedReader(new FileReader(filename))) {
            String str = in.readLine();
            while (str != null) {
                arr.addAll(Arrays.asList(str.split(" ")));
                str = in.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (_is_palindrome(arr.get(i), arr.get(j))) {
                    System.out.println(arr.get(i) + " - " + arr.get(j));
                    arr.remove(j--);
                }
            }
        }
    }
}
