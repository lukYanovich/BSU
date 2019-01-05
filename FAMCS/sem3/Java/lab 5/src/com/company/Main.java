package com.company;


import com.company.Comparators.SortedByMainMember;

import java.util.Arrays;
import java.util.Iterator;

public class Main {

    public static void main(String[] args) {
        FuzzyNumber a1 = new FuzzyNumber(2.0, 0.1, 0.1);
        FuzzyNumber a2 = FuzzyNumber.fromString("10 1 2");
        FuzzyNumber a3 = a1.add(a2);
        FuzzyNumber a4 = a1.sub(a2);
        FuzzyNumber a5 = a1.mul(a2);
        FuzzyNumber a6 = a1.div(a2);
        FuzzyNumber a7 = a1.inverse();
        System.out.println("a: " + a1);
        System.out.println("b: " + a2);
        System.out.println("a+b = " + a3);
        System.out.println("a-b = " + a4);
        System.out.println("a*b = " + a5);
        System.out.println("a/b = " + a6);
        System.out.println("inverse a = " + a7);

        FuzzyNumber[] arr = {a1, a2, a3, a4, a5, a6, a7};
        Arrays.sort(arr, new SortedByMainMember());
        System.out.println("\nсортированный массив:");
        for (FuzzyNumber i : arr)
            System.out.println(i);

        System.out.println("\nполя a:");
        Iterator iter = a1.iterator();
        while (iter.hasNext())
            System.out.println(iter.next());
    }
}
