package com.company.logic;

import static org.testng.Assert.*;

import org.testng.annotations.Test;

import java.util.Arrays;
import java.util.List;

public class LogicTest {
    private static double[][] input = {
            {1, 1, 3, 1, 2, 2}, //0 - ok
            {1, 1, 2, 2, 3, 1}, //1 - ok
            {1, 1, 2, 2, 3, 3}, //2 - fail
            {1, 1, 3, 1, 3, 1}, //3 - fail
            {1, 1, 1, 1, 1, 1}, //4 - fail
            {10, 1, 3, 1, 2, 2}, //5 - ok
            {1, 12, 7, 1, 3, 2}, //6 - ok
            {7, 7, 3, 1, 5, 2}, //7 - ok
            {11, 11, 33, 31, 22, 22}, //8 - ok
            {10, 1, 1, 10, 4, 4}, //9 - ok
    };

    @Test
    public void testCheck_triangle0() {
        int number_test = 0;
        assertTrue(Logic.check_triangle(input[number_test][0], input[number_test][1],
                input[number_test][2], input[number_test][3],
                input[number_test][4], input[number_test][5]));
    }

    @Test
    public void testCheck_triangle1() {
        int number_test = 1;
        assertTrue(Logic.check_triangle(input[number_test][0], input[number_test][1],
                input[number_test][2], input[number_test][3],
                input[number_test][4], input[number_test][5]));
    }

    @Test
    public void testCheck_triangle2() {
        int number_test = 2;
        assertFalse(Logic.check_triangle(input[number_test][0], input[number_test][1],
                input[number_test][2], input[number_test][3],
                input[number_test][4], input[number_test][5]));
    }

    @Test
    public void testCheck_triangle3() {
        int number_test = 3;
        assertFalse(Logic.check_triangle(input[number_test][0], input[number_test][1],
                input[number_test][2], input[number_test][3],
                input[number_test][4], input[number_test][5]));
    }

    @Test
    public void testCheck_triangle4() {
        int number_test = 4;
        assertFalse(Logic.check_triangle(input[number_test][0], input[number_test][1],
                input[number_test][2], input[number_test][3],
                input[number_test][4], input[number_test][5]));
    }

    @Test
    public void testCheck_triangle5() {
        int number_test = 5;
        assertTrue(Logic.check_triangle(input[number_test][0], input[number_test][1],
                input[number_test][2], input[number_test][3],
                input[number_test][4], input[number_test][5]));
    }

    @Test
    public void testCheck_triangle6() {
        int number_test = 6;
        assertTrue(Logic.check_triangle(input[number_test][0], input[number_test][1],
                input[number_test][2], input[number_test][3],
                input[number_test][4], input[number_test][5]));
    }

    @Test
    public void testCheck_triangle7() {
        int number_test = 7;
        assertTrue(Logic.check_triangle(input[number_test][0], input[number_test][1],
                input[number_test][2], input[number_test][3],
                input[number_test][4], input[number_test][5]));
    }

    @Test
    public void testCheck_triangle8() {
        int number_test = 8;
        assertTrue(Logic.check_triangle(input[number_test][0], input[number_test][1],
                input[number_test][2], input[number_test][3],
                input[number_test][4], input[number_test][5]));
    }

    @Test
    public void testCheck_triangle9() {
        int number_test = 9;
        assertTrue(Logic.check_triangle(input[number_test][0], input[number_test][1],
                input[number_test][2], input[number_test][3],
                input[number_test][4], input[number_test][5]));
    }
}
