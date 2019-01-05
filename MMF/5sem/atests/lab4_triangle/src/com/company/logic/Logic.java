package com.company.logic;

import com.company.entity.Point;

public class Logic {
    public static boolean check_triangle(double ax, double ay, double bx, double by, double cx, double cy) {
        Point a = new Point(ax, ay);
        Point b = new Point(bx, by);
        Point c = new Point(cx, cy);
        double ab_c = check_side(a, b, c);
        double bc_a = check_side(b, c, a);
        double ca_b = check_side(c, a, b);
        return ab_c * bc_a > 0 && bc_a * ca_b > 0;
    }

    private static double check_side(Point a, Point b, Point c) {
        return (c.getX() - a.getX()) * (b.getY() - a.getY()) - (c.getY() - a.getY()) * (b.getX() - a.getX());
    }
}
