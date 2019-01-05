package com.company.comparators;

import com.company.Account;

import java.util.Comparator;

/**
 * Created by Александр on 10.11.2016.
 */
public class CompareByDateInc implements Comparator<Account> {
    @Override
    public int compare(Account o1, Account o2) {
        return o1.getDateOfPayment().compareTo(o2.getDateOfPayment());
    }
}
