package com.company.Comparators;

import com.company.FuzzyNumber;

import java.util.Comparator;


public class SortedByRigthMember implements Comparator<FuzzyNumber> {

    @Override
    public int compare(FuzzyNumber o1, FuzzyNumber o2) {
        return Double.compare(o1.getRight(), o2.getRight());
    }
}
