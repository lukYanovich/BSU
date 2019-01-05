package A.start;

import A.entities.Element;
import A.entities.One_dimensional_array;

import java.io.BufferedReader;
import java.io.FileReader;

public class Main {
    public static void main(String[] args) {
        String filename = "C:\\Projects\\MMF\\4sem\\java\\lab4\\src\\A\\resources\\input.txt";
        try (BufferedReader in = new BufferedReader(new FileReader(filename))) {
            One_dimensional_array arr1 = new One_dimensional_array();
            One_dimensional_array arr2 = new One_dimensional_array();
            String str = in.readLine();
            for (String s : str.split(" "))
                arr1.add(new Element(Integer.parseInt(s)));
            str = in.readLine();
            for (String s : str.split(" "))
                arr2.add(new Element(Integer.parseInt(s)));
            System.out.println("сложение:");
            (arr1.add_arr(arr2)).print();
            System.out.println("разность");
            (arr1.sub_arr(arr2)).print();
            System.out.println("перемножение:");
            (arr1.mul_arr(arr2)).print();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
