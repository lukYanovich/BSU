package com.company;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            System.out.println("введите строку:");
            StringBuffer str = new StringBuffer(in.nextLine());
            if (str.indexOf("(") == -1 || str.indexOf(")") == -1)
                throw new Exception("в строке нет парных скобок");
            int n = 0, k = 0, counter = 0;
            while (k != -1 && n != -1) {
                k = str.indexOf(")", n + 1);
                n = str.lastIndexOf("(", k);
                if (n < k && n != -1) {
                    str.deleteCharAt(n);
                    str.deleteCharAt(k - 1);
                    counter++;
                    n = 0;
                } else
                    n = k;
            }
            if (counter == 0)
                throw new Exception("в строке нет скобок для удаления");
            System.out.println(str);
        } catch (Throwable e) {
            System.err.println(e);
        }
    }
}
