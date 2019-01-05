package com.company.entity;

import java.util.ArrayList;
import java.util.List;

public class Student {
    private String surname;
    private String name;
    private Integer group;
    private List<Integer> exam_list;


    public Student(String name, String surname, Integer group, List<Integer> exam_list) {
        this.name = name;
        this.surname = surname;
        this.group = group;
        this.exam_list = new ArrayList<>(exam_list);
    }

    @Override
    public String toString() {
        return "Student{" +
                "surname='" + surname + '\'' +
                ", name='" + name + '\'' +
                ", group=" + group +
                ", exam_list=" + exam_list +
                '}';
    }

    public String getSurname() {
        return surname;
    }

    public String getName() {
        return name;
    }

    public Integer getGroup() {
        return group;
    }

    public List<Integer> getExam_list() {
        return exam_list;
    }
}
