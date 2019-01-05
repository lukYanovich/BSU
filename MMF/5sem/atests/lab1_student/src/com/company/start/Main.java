package com.company.start;

import com.company.entity.Group_Score;
import com.company.entity.Student;
import com.company.logic.Logic;

import java.util.List;

public class Main {

    public static void main(String[] args) {
        String filename = "./src/com/company/resources/data.txt";
        List<Student> list_student = Logic.read_file(filename);
        List<Group_Score> gs = Logic.average_score_for_groups(list_student);
        for (Group_Score i : gs) {
            System.out.println(i);
        }
    }
}
