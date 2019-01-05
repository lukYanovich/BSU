package com.company.Comparators;

import com.company.FuzzyNumber;

import java.util.Comparator;


public class SortedByMainMember implements Comparator<FuzzyNumber> {

    @Override
    public int compare(FuzzyNumber o1, FuzzyNumber o2) {
        return Double.compare(o1.getX(), o2.getX());
    }
}
