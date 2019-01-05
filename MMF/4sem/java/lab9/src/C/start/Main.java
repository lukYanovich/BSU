package C.start;

import C.entities.Person;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        String beg_dir = "C:\\Projects\\MMF\\4sem\\java\\lab9\\src\\C\\resources";
        String new_folder_name = "\\new_folder", input_file = "\\input.txt", out_file = "\\output.txt";
        File folder = new File(beg_dir + new_folder_name);
        if (!folder.mkdir())
            System.err.println("папка уже создана");
        try (
                BufferedReader in = new BufferedReader(new FileReader(beg_dir + input_file));
                BufferedWriter out = new BufferedWriter(new FileWriter(folder.toString() + out_file))
        ) {
            List<Person> arr = new ArrayList<>();
            String str = in.readLine();
            while (str != null) {
                String[] str_arr = str.split(";");
                Person person = new Person(str_arr[0], str_arr[1]);
                arr.add(person);
                str = in.readLine();
            }
            for (Person person : arr)
                if (person.get_phone_number().matches("^[kj]+.+$"))
                    out.write(person.print_to_file());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
