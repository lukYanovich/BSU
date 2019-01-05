package com.company;

import com.company.logic.Logic;

public class Main {

    public static void main(String[] args) {
        double ax = 1, ay = 1;
        double bx = 2, by = 2;
        double cx = 3, cy = 3;
        System.out.println(Logic.check_triangle(ax, ay, bx, by, cx, cy));
    }
}
