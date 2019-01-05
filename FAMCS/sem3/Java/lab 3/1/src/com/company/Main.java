package com.company;

import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void createMatrix(int[][] arr, int n, int m) {
        //Random rand = new Random();
        Scanner in = new Scanner(System.in);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                //arr[i][j] = rand.nextInt(2 * n) - n;//от -n до n
                arr[i][j] = in.nextInt();
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

    public static int[][] copy(int[][] a, int n, int m) {
        int[][] arr = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                arr[i][j] = a[i][j];
        a = null;
        return arr;
    }

    public static void main(String[] args) {
        System.out.print("введите n: ");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), m = n;
        int[][] arr = new int[n][n];
        createMatrix(arr, n);

        for (int i = 0; i < n; i++) {
            boolean flag = false;
            for (int j = 0; j < m; j++)
                if (arr[i][j] != 0) {
                    flag = true;
                    break;
                }
            if (flag == false) {
                for (int j = 0; j < m; j++) {
                    arr[i][j] = arr[n - 1][j];
                    arr[n - 1][j] = 0;
                }
                n--;
            }
        }
        for (int i = 0; i < m; i++) {
            boolean flag = false;
            for (int j = 0; j < n; j++)
                if (arr[j][i] != 0) {
                    flag = true;
                    break;
                }
            if (flag == false) {
                for (int j = 0; j < n; j++) {
                    arr[j][i] = arr[j][m - 1];
                    arr[j][m - 1] = 0;
                }
                m--;
            }
        }
        arr = copy(arr, n, m);
        try {
            printMatrix(arr, n, m);
        } catch (Throwable e) {
            System.err.println(e);
        }
    }
}
