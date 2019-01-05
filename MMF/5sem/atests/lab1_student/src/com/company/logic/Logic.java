package com.company.logic;

import com.company.entity.Group_Score;
import com.company.entity.Student;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Logic {
    public static List<Student> read_file(String filename) {
        List<String> list = new ArrayList<>();
        try (BufferedReader br = Files.newBufferedReader(Paths.get(filename))) {
            list = br.lines().collect(Collectors.toList());
        } catch (IOException e) {
            e.printStackTrace();
        }
        List<Student> list_student = new ArrayList<>();
        for (String line : list) {
            String[] arr = line.split(" ");
            Integer group = Integer.parseInt(arr[2]);
            List<Integer> exam_list = new ArrayList<>();
            for (int i = 3; i < arr.length; i++) {
                exam_list.add(Integer.parseInt(arr[i]));
            }
            Student student = new Student(arr[0], arr[1], group, exam_list);
            list_student.add(student);
        }
        return list_student;
    }

    public static List<Group_Score> average_score_for_groups(List<Student> list) {
        List<List<Integer>> group_scores_number = new ArrayList<>();
        for (Student student : list) {
            Integer group = student.getGroup();
            Integer score = new Integer(0);
            for (Integer number : student.getExam_list()) {
                score += number;
            }
            List<Integer> gsn = new ArrayList<>();
            gsn.add(group);
            gsn.add(score);
            gsn.add(student.getExam_list().size());
            group_scores_number.add(gsn);
        }
        for (int i = 0; i < group_scores_number.size() - 1; i++) {
            for (int j = i + 1; j < group_scores_number.size(); j++) {
                List<Integer> a = group_scores_number.get(i);
                List<Integer> b = group_scores_number.get(j);
                if (a.get(0).equals(b.get(0))) {
                    a.set(1, a.get(1) + b.get(1));
                    a.set(2, a.get(2) + b.get(2));
                    group_scores_number.set(i, a);
                    group_scores_number.remove(j--);
                }
            }
        }
        List<Group_Score> group_score = new ArrayList<>();
        for (List<Integer> l : group_scores_number) {
            Double score = new Double(l.get(1));
            score /= l.get(2);
            Group_Score gs = new Group_Score(l.get(0), score);
            group_score.add(gs);
        }
        return group_score;
    }
}
