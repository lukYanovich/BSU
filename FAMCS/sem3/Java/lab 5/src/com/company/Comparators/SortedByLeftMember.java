package com.company.Comparators;

import com.company.FuzzyNumber;

import java.util.Comparator;


public class SortedByLeftMember implements Comparator<FuzzyNumber> {

    @Override
    public int compare(FuzzyNumber o1, FuzzyNumber o2) {
        return Double.compare(o1.getLeft(), o2.getLeft());
    }
}
