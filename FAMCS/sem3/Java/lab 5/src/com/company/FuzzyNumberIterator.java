package com.company;


import java.util.Iterator;
import java.util.NoSuchElementException;

final public class FuzzyNumberIterator implements Iterator<Double> {

    private int index = 0;
    private FuzzyNumber m;

    public FuzzyNumberIterator(FuzzyNumber m) {
        this.m = m;
    }


    @Override
    public boolean hasNext() {
        return index <= 2;
    }


    @Override
    public Double next() {
        switch (index) {
            case 0:
                index++;
                return m.getLeft();
            case 1:
                index++;
                return m.getX();
            case 2:
                index++;
                return m.getRight();
            default:
                throw new NoSuchElementException("FuzzyNumber: выход за рамки");
        }
    }
}
