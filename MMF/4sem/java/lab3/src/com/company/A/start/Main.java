package com.company.A.start;

import com.company.A.entity.Student;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class Main {

    private static void _print(List<Student> arr) {
        for (Student student : arr) {
            System.out.println(student);
        }
    }


    private static void _taskA(List<Student> arr, String faculty) {
        System.out.println("список студентов факультета '" + faculty + "':");
        for (Student student : arr)
            if (student.get_faculty().equals(faculty))
                System.out.println(student);
    }


    private static void _taskB(List<Student> arr) {
        arr.sort(new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                if (o1.get_faculty().equals(o2.get_faculty()))
                    return o1.get_course() - o2.get_course();
                else return o1.get_faculty().compareTo(o2.get_faculty());
            }
        });
        for (int i = 0; i < arr.size(); i++) {
            System.out.println("факультет '" + arr.get(i).get_faculty() + "', курс '" + arr.get(i).get_course() + "':");
            System.out.println(arr.get(i));
            for (int j = i + 1; j < arr.size(); j++)
                if (arr.get(i).get_faculty().equals(arr.get(j).get_faculty())
                        && arr.get(i).get_course() == arr.get(j).get_course()) {
                    System.out.println(arr.get(j));
                    arr.remove(j--);
                } else
                    break;
            System.out.println();
        }
    }


    private static void _taskC(List<Student> arr, int year) {
        System.out.println("студенты, родившиеся после '" + year + "' года:");
        for (Student student : arr) {
            Calendar calendar = Calendar.getInstance();
            calendar.setTime(student.get_born_date());
            if (calendar.get(Calendar.YEAR) > year)
                System.out.println(student);
        }
    }


    private static void _taskD(List<Student> arr, String faculty, int course, int group) {
        System.out.println("список группы:\n(факультет '" + faculty + "', курс '" + course + "', группа '" + group + "')");
        for (Student student : arr)
            if (student.get_faculty().equals(faculty)
                    && student.get_group() == group
                    && student.get_course() == course)
                System.out.println(student);
    }


    public static void main(String[] args) {
        String filename = "C:\\Projects\\MMF\\4sem\\java\\lab3\\src\\com\\company\\A\\resources\\input.txt";
        List<Student> arr = new ArrayList<>();
        try (BufferedReader in = new BufferedReader(new FileReader(filename))) {
            String str = in.readLine();
            while (str != null) {
                Student student = new Student();
                String[] temp = str.split("; ");
                student.set_surname(temp[0]);
                student.set_name(temp[1]);
                student.set_patronymic(temp[2]);
                SimpleDateFormat formatter = new SimpleDateFormat("dd-MM-yyyy");
                student.set_born_date(formatter.parse(temp[3]));
                student.set_address(temp[4]);
                student.set_phone_number(temp[5]);
                student.set_faculty(temp[6]);
                student.set_course(Integer.parseInt(temp[7]));
                student.set_group(Integer.parseInt(temp[8]));
                arr.add(student);
                str = in.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ParseException e) {
            System.err.println("неверно записана дата");
            e.printStackTrace();
        }
        //_print(arr);
        _taskA(arr, "фпми");
        _taskB(arr);
        _taskC(arr, 1995);
        _taskD(arr, "ммф", 1, 5);
    }
}
