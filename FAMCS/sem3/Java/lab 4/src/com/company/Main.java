package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        NonlinearEquation eq = null;
        System.out.println("введите границы промежутка: ");
        try (Scanner in = new Scanner(System.in)) {
            System.out.print("a: ");
            Double a = new Double(in.nextDouble());
            System.out.print("b: ");
            Double b = new Double(in.nextDouble());
            if (a > b) {
                Double temp = b;
                b = a;
                a = temp;
            }

            //массив коэффициентов - удобно
            double[] arr = {1, -3, 0, 3};
            eq = new NonlinearEquation(arr);
            System.out.println("\nуравнение: " + eq.print());

            System.out.println("\nрешение на интервале [" + a + "; " + b + "]: " + eq.getSolutionOnInterval(a, b));
        } catch (Throwable e) {
            System.err.println(e);
        } finally {
            try {
                NonlinearEquation temp = new NonlinearEquation(eq);
                eq.setRatioByIndex(1, 2.0);
                System.out.println("\nисходное уравнение после изменений: " + eq.print());
                System.out.println("\nуравнение \"temp\" после изменений исходного: " + temp.print());
            } catch (Throwable ex) {
                System.err.println(ex);
            }
        }
    }
}
