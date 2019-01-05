package com.company.C.start;

import com.company.C.entity.Vector3D;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static void print(List<Vector3D> arr) {
        for (Vector3D v : arr)
            System.out.println(v);
    }


    public static void main(String[] args) {
        String filename = "C:\\Projects\\MMF\\4sem\\java\\lab3\\src\\com\\company\\C\\resources\\input.txt";
        List<Vector3D> arr = new ArrayList<>();
        try (BufferedReader in = new BufferedReader(new FileReader(filename))) {
            String str = in.readLine();
            while (str != null) {
                String[] temp = str.split(" ");
                Vector3D v = new Vector3D(Integer.parseInt(temp[0])
                        , Integer.parseInt(temp[1])
                        , Integer.parseInt(temp[2]));
                arr.add(v);
                str = in.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        //print(arr);
        System.out.println("компланарные:");
        for (int i = 0; i < arr.size() - 2; i++)
            for (int j = i + 1; j < arr.size() - 1; j++)
                for (int k = j + 1; k < arr.size(); k++)
                    if (arr.get(i).is_coplanar(arr.get(j), arr.get(k))) {
                        List<Vector3D> list = new ArrayList<>();
                        list.add(arr.get(i));
                        list.add(arr.get(j));
                        list.add(arr.get(k));
                        arr.remove(k--);
                        print(list);
                        System.out.println();
                    }
    }
}
