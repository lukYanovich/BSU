package com.company;


import java.util.Arrays;
import java.util.Iterator;
import java.util.List;


public class FuzzyNumber implements Iterable<Double> {

    private Double x, left, right;

    public Double getX() {
        return x;
    }

    public Double getLeft() {
        return left;
    }

    public Double getRight() {
        return right;
    }

    private FuzzyNumber() {
    }


    public FuzzyNumber(Double _x, Double el, Double er) {
        x = _x;
        left = x - el;
        right = x + er;
        if (left >= x || right <= x || left == 0 || right == 0)
            throw new IllegalArgumentException("объект не может быть создан, т.к. неверны аргументы");
    }


    public FuzzyNumber add(FuzzyNumber obj) {
        FuzzyNumber temp = new FuzzyNumber();
        temp.x = x + obj.x;
        temp.left = left + obj.left;
        temp.right = right + obj.right;
        return temp;
    }


    public FuzzyNumber sub(FuzzyNumber obj) {
        FuzzyNumber temp = new FuzzyNumber();
        temp.x = x - obj.x;
        temp.left = left - obj.right;
        temp.right = right - obj.left;
        return temp;
    }


    public FuzzyNumber mul(FuzzyNumber obj) {
        FuzzyNumber temp = new FuzzyNumber();
        temp.x = x * obj.x;
        temp.left = left * obj.left;
        temp.right = right * obj.right;
        return temp;
    }


    public FuzzyNumber div(FuzzyNumber obj) {
        if (obj.x == 0)
            throw new IllegalArgumentException("деление на 0 невозможно");
        FuzzyNumber temp = new FuzzyNumber();
        temp.x = x / obj.x;
        temp.left = left / obj.right;
        temp.right = right / obj.left;
        return temp;
    }


    public FuzzyNumber inverse() {
        if (x == 0)
            throw new IllegalArgumentException("нельзя вычислить обратное число(деление на 0)");
        FuzzyNumber temp = new FuzzyNumber();
        temp.x = 1.0 / x;
        temp.left = 1.0 / right;
        temp.right = 1.0 / left;
        return temp;
    }

    //в целях теста
    public void assign(FuzzyNumber obj) {
        x = obj.x;
        left = obj.left;
        right = obj.right;
    }


    @Override
    public String toString() {
        return "" + x + ' ' + (x - left) + ' ' + (right - x);
    }


    static public FuzzyNumber fromString(String str) {
        List<String> temp = Arrays.asList(str.split(" "));
        FuzzyNumber t = new FuzzyNumber();
        try {
            t.x = Double.parseDouble(temp.get(0));
            t.left = t.x - Double.parseDouble(temp.get(1));
            t.right = t.x + Double.parseDouble(temp.get(2));
        } catch (Throwable e) {
            System.err.println("попытка преобразовать к double при создании объекта FuzzyNumber");
        }
        return t;
    }


    @Override
    public Iterator<Double> iterator() {
        return new FuzzyNumberIterator(this);
    }
}
