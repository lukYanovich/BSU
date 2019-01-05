package C.start;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static void _check(List<List<Integer>> arr) throws Exception {
        if (arr.isEmpty())
            throw new Exception("матрица пуста");
        int size = arr.get(0).size();
        for (List<Integer> line : arr)
            if (line.size() != size)
                throw new Exception("это не матрица");
    }


    private static void _print(List<List<Integer>> arr) {
        for (List<Integer> line : arr) {
            for (Integer element : line) {
                System.out.print(element + " ");
            }
            System.out.println();
        }
    }


    private static void _moves(List<List<Integer>> arr) {
        int number_of_moves = 0;
        for (int i = 0; i < arr.size() - number_of_moves; i++) {
            for (int j = 0; j < arr.get(0).size(); j++) {
                if (arr.get(i).get(j) == 0) {
                    List<Integer> temp = arr.get(arr.size() - 1 - number_of_moves);
                    arr.set(arr.size() - 1 - number_of_moves++, arr.get(i));
                    arr.set(i, temp);
                    break;
                }
            }
        }
    }


    public static void main(String[] args) {
        String filename = "C:\\Projects\\MMF\\4sem\\java\\lab2\\src\\C\\resources\\input.txt";
        List<List<Integer>> arr = new ArrayList<>();
        try (BufferedReader in = new BufferedReader(new FileReader(filename))) {
            String str = in.readLine();
            while (str != null) {
                List<Integer> temp_list = new ArrayList<>();
                for (String number : str.split(" ")) {
                    temp_list.add(Integer.parseInt(number));
                }
                arr.add(temp_list);
                str = in.readLine();
            }
            _check(arr);
            _moves(arr);
            _print(arr);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
