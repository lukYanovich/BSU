package com.company;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        String filename = "Accounts.dat";
        try (Scanner in = new Scanner(System.in)) {
            append_in_file(filename, in);

            print_file(filename);

            //delete_file(filename);
        } catch (Throwable e) {
            System.err.println(e);
        }
    }


    static Account read_account(String filename, Scanner in) {
        if (in.hasNextLine())
            return Account.read(in);
        else
            return null;
    }


    static void delete_file(String filename) {
        File file = new File(filename);
        file.delete();
    }


    static void append_in_file(String filename, Scanner in) throws IOException {
        System.out.println("введите параметры счёта(для завершения ctrl+d):");
        try (RandomAccessFile raf = new RandomAccessFile(filename, "rw")) {
            Account acc = read_account(filename, in);
            while (acc != null) {
                Account.writeObject(raf, acc);
                acc = read_account(filename, in);
            }
        }
    }


    static void print_file(String filename) throws IOException, ClassNotFoundException {
        try (RandomAccessFile raf = new RandomAccessFile(filename, "rw")) {
            long pos = raf.getFilePointer();
            while (pos < raf.length()) {
                Account acc = (Account) Account.readObject(raf, pos);
                System.out.println(pos + ": " + acc);
                pos = raf.getFilePointer();
            }
        }
    }
}
