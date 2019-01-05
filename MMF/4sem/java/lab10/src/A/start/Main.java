package A.start;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        String filename = "C:\\Projects\\MMF\\4sem\\java\\lab10\\src\\A\\resources\\input.txt";
        List<Integer> arr = new ArrayList<>();
        try (BufferedReader in = new BufferedReader(new FileReader(filename))) {
            for (String s : in.readLine().split(" "))
                arr.add(Integer.parseInt(s));
        } catch (IOException e) {
            e.printStackTrace();
        }
        arr.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return -o1.compareTo(o2);
            }
        });
        System.out.println(arr);
    }
}
