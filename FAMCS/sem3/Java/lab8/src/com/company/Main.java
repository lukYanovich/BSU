package com.company;

import com.company.comparators.CompareByDateDec;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // write your code here
        String filename = "Accounts.dat";
        try (Scanner in = new Scanner(System.in)) {
            List<Account> arr = new ArrayList<>();
            arr.add(new Account(21, 22, "городская", "голубев",
                    (new GregorianCalendar(1999, Calendar.SEPTEMBER, 12).getTime()),
                    45121, 4, 7));
            arr.add(new Account(121, 2, "донская", "щедрин",
                    new GregorianCalendar(1999, Calendar.OCTOBER, 8).getTime(),
                    421, 74, 8));
            arr.add(new Account(11, 17, "ленина", "королёв",
                    new GregorianCalendar(1999, Calendar.DECEMBER, 13).getTime(),
                    77421, 40, 1));
            arr.add(new Account(65, 14, "кижеватова", "иванов",
                    (new GregorianCalendar(2001, Calendar.NOVEMBER, 4).getTime()),
                    5454, 10, 4));
            arr.add(new Account(1, 102, "голодеда", "лифшиц",
                    (new GregorianCalendar(1997, Calendar.OCTOBER, 8).getTime()),
                    7621, 1, 0));
            arr.add(new Account(101, 13, "свердлова", "финн",
                    (new GregorianCalendar(1999, Calendar.MARCH, 19).getTime()),
                    68557, 5, 30));
            arr.add(new Account(94, 3, "северная", "орешкин",
                    (new GregorianCalendar(2002, Calendar.JUNE, 20).getTime()),
                    4591, 21, 3));
            //deleteByIndex(arr, "21", Account.index.NUMBER_OF_HOUSE);
            //arr.sort(new CompareByDateDec());
            write_in_file(filename, arr);
            List<Account> list = read_from_file(filename);
            print(list);
        } catch (Throwable e) {
            System.err.println(e);
        }
    }


    static void write_in_file(String filename, List<Account> arr) throws IOException {
        File file = new File(filename);
        file.delete();
        try (RandomAccessFile raf = new RandomAccessFile(filename, "rw")) {
            for (Account i : arr)
                Account.writeObject(raf, i);
        }
    }


    static void print(List<Account> list) {
        for (Account i : list)
            System.out.println(i);
    }

    static List<Account> read_from_file(String filename) throws IOException, ClassNotFoundException {
        List<Account> arr = new ArrayList<>();
        try (RandomAccessFile raf = new RandomAccessFile(filename, "rw")) {
            long pos = raf.getFilePointer();
            while (pos < raf.length()) {
                arr.add((Account) Account.readObject(raf, pos));
                pos = raf.getFilePointer();
            }
            return arr;
        }
    }


    static List<Account> sortByIndex(List<Account> arr, Comparator<Account> comparator) {
        List<Account> temp = new ArrayList<>(arr);
        temp.sort(comparator);
        return temp;
    }


    static void deleteByIndex(List<Account> arr, Integer index, Account.index typeIndex) throws Exception {
        switch (typeIndex) {
            case NUMBER_OF_HOUSE: {
                for (int i = 0; i < arr.size(); i++)
                    if (index.compareTo(arr.get(i).getNumberOfHouse()) == 0)
                        arr.remove(arr.get(i));
                break;
            }
            case NUMBER_OF_FLAT: {
                for (int i = 0; i < arr.size(); i++)
                    if (index.compareTo(arr.get(i).getNumberOfFlat()) == 0)
                        arr.remove(arr.get(i));
                break;
            }
            default:
                throw new Exception("неожиданные данные");
        }
    }

    static void deleteByIndex(List<Account> arr, String index) {
        for (int i = 0; i < arr.size(); i++)
            if (index.compareTo(arr.get(i).getFio()) == 0)
                arr.remove(arr.get(i));
    }

    static void deleteByIndex(List<Account> arr, Date index) {
        for (int i = 0; i < arr.size(); i++)
            if (index.compareTo(arr.get(i).getDateOfPayment()) == 0)
                arr.remove(arr.get(i));
    }


    static List<Account> findByIndex(List<Account> arr, Integer index, Account.index typeIndex) throws Exception {
        List<Account> temp = new ArrayList<>();
        switch (typeIndex) {
            case NUMBER_OF_HOUSE: {
                for (Account i : arr)
                    if (i.getNumberOfHouse().compareTo(index) == 0)
                        temp.add(i);
                break;
            }
            case NUMBER_OF_FLAT: {
                for (Account i : arr)
                    if (i.getNumberOfFlat().compareTo(index) == 0)
                        temp.add(i);
                break;
            }
            default:
                throw new Exception("неожиданные данные");
        }
        return temp;
    }

    static List<Account> findByIndex(List<Account> arr, String index) {
        List<Account> temp = new ArrayList<>();
        for (Account i : arr)
            if (i.getFio().compareTo(index) == 0)
                temp.add(i);
        return temp;
    }

    static List<Account> findByIndex(List<Account> arr, Date index) {
        List<Account> temp = new ArrayList<>();
        for (Account i : arr)
            if (i.getDateOfPayment().compareTo(index) == 0)
                temp.add(i);
        return temp;
    }


    static List<Account> findByIndexInc(List<Account> arr, Integer index, Account.index typeIndex) throws Exception {
        List<Account> temp = new ArrayList<>();
        switch (typeIndex) {
            case NUMBER_OF_HOUSE: {
                for (Account i : arr)
                    if (i.getNumberOfHouse().compareTo(index) >= 0)
                        temp.add(i);
                break;
            }
            case NUMBER_OF_FLAT: {
                for (Account i : arr)
                    if (i.getNumberOfFlat().compareTo(index) >= 0)
                        temp.add(i);
                break;
            }
            default:
                throw new Exception("неожиданные данные");
        }
        return temp;
    }

    static List<Account> findByIndexInc(List<Account> arr, String index) {
        List<Account> temp = new ArrayList<>();
        for (Account i : arr)
            if (i.getFio().compareTo(index) >= 0)
                temp.add(i);
        return temp;
    }

    static List<Account> findByIndexInc(List<Account> arr, Date index) {
        List<Account> temp = new ArrayList<>();
        for (Account i : arr)
            if (i.getDateOfPayment().compareTo(index) >= 0)
                temp.add(i);
        return temp;
    }


    static List<Account> findByIndexDec(List<Account> arr, Integer index, Account.index typeIndex) throws Exception {
        List<Account> temp = new ArrayList<>();
        switch (typeIndex) {
            case NUMBER_OF_HOUSE: {
                for (Account i : arr)
                    if (i.getNumberOfHouse().compareTo(index) <= 0)
                        temp.add(i);
                break;
            }
            case NUMBER_OF_FLAT: {
                for (Account i : arr)
                    if (i.getNumberOfFlat().compareTo(index) <= 0)
                        temp.add(i);
                break;
            }
            default:
                throw new Exception("неожиданные данные");
        }
        return temp;
    }

    static List<Account> findByIndexDec(List<Account> arr, String index) {
        List<Account> temp = new ArrayList<>();
        for (Account i : arr)
            if (i.getFio().compareTo(index) <= 0)
                temp.add(i);
        return temp;
    }

    static List<Account> findByIndexDec(List<Account> arr, Date index) {
        List<Account> temp = new ArrayList<>();
        for (Account i : arr)
            if (i.getDateOfPayment().compareTo(index) <= 0)
                temp.add(i);
        return temp;
    }
}
