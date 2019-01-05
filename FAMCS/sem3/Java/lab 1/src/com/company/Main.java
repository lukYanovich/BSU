package com.company;

import java.util.Scanner;

public class Main {
    public static double myFunc(double x, int k) {
        double aNext = x;
        for (int i = 1; Math.abs(aNext) >= Math.pow(10.0, -k); ++i) {
            aNext *= x * i / (i + 1);
            x += aNext;
        }
        return -x;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("введите х: ");
        double x = in.nextDouble();
        System.out.print("введите k: ");
        int k = in.nextInt();
        try {
            if (k <= 1)
                throw new ArithmeticException("неверное k");
            System.out.printf("после вычистелний: %." + k + "f", myFunc(x, k));
            System.out.println();
        } catch (Throwable e) {
            System.err.println(e);
        } finally {
            System.out.printf("значение из Math: %." + k + "f", Math.log(1.0 - x));
            System.out.println();
        }
    }
}
