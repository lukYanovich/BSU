package com.company;

import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void createMatrix(int[][] arr, int n, int m) {
        Random rand = new Random();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = rand.nextInt(2 * n) - n; //от -n до n
    }

    public static void createMatrix(int[][] arr, int n) {
        createMatrix(arr, n, n);
    }

    public static void printMatrix(int[][] arr, int n, int m) throws Exception {
        if (n < 1 || m < 1)
            throw new Exception("это не матрица");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                System.out.print(arr[i][j] + "\t\t");
            System.out.println();
        }
    }

    public static void printMatrix(int[][] arr, int n) throws Exception {
        printMatrix(arr, n, n);
    }

    public static void main(String[] args) {
        System.out.print("введите n: ");
        try (Scanner in = new Scanner(System.in)) {
            int n = in.nextInt();
            int[][] arr = new int[n][n];
            createMatrix(arr, n);

            int maxInc = 0, maxDec = 0, maxI = 0, minI = 0;
            for (int i = 0; i < n; i++) {
                Counter.Inner.cleanCounter();
                for (int j = 1; j < n; j++)
                    Counter.Inner.check(arr[i][j - 1], arr[i][j]);
                if (maxInc < Counter.Inner.getMaxInc()) {
                    maxInc = Counter.Inner.getMaxInc();
                    maxI = i;
                }
                if (maxDec < Counter.Inner.getMaxDec()) {
                    maxDec = Counter.Inner.getMaxDec();
                    minI = i;
                }
            }

            printMatrix(arr, n);
            System.out.println("максимальное число возрастающих(строка " + ++maxI + "): " + maxInc);
            System.out.println("максимальное число убывающих(строка " + ++minI + "): " + maxDec);
        } catch (Throwable e) {
            System.err.println(e);
        }
    }
}
