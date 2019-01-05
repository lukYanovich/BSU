package com.company.A.entity;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Student {
    private static int _count = 1;
    private int _id;
    private String _surname;
    private String _name;
    private String _patronymic;
    private Date _born_date;
    private String _address;
    private String _phone_number;
    private String _faculty;
    private int _course;
    private int _group;


    public Student() {
        this._id = Student._count++;
    }


    @Override
    public String toString() {
        SimpleDateFormat sd = new SimpleDateFormat("dd.MM.yyyy");
        return "Student{ " +
                "id=" + _id +
                ", surname='" + _surname + '\'' +
                ", name='" + _name + '\'' +
                ", patronymic='" + _patronymic + '\'' +
                ", born_date=" + sd.format(_born_date) +
                ", address='" + _address + '\'' +
                ", phone_number='" + _phone_number + '\'' +
                ", faculty='" + _faculty + '\'' +
                ", course=" + _course +
                ", group=" + _group +
                " }";
    }


    public String get_surname() {
        return _surname;
    }

    public void set_surname(String _surname) {
        this._surname = _surname;
    }

    public String get_name() {
        return _name;
    }

    public void set_name(String _name) {
        this._name = _name;
    }

    public String get_patronymic() {
        return _patronymic;
    }

    public void set_patronymic(String _patronymic) {
        this._patronymic = _patronymic;
    }

    public Date get_born_date() {
        return _born_date;
    }

    public void set_born_date(Date _born_date) {
        this._born_date = _born_date;
    }

    public String get_address() {
        return _address;
    }

    public void set_address(String _address) {
        this._address = _address;
    }

    public String get_phone_number() {
        return _phone_number;
    }

    public void set_phone_number(String _phone_number) {
        this._phone_number = _phone_number;
    }

    public String get_faculty() {
        return _faculty;
    }

    public void set_faculty(String _faculty) {
        this._faculty = _faculty;
    }

    public int get_course() {
        return _course;
    }

    public void set_course(int _course) {
        this._course = _course;
    }

    public int get_group() {
        return _group;
    }

    public void set_group(int _group) {
        this._group = _group;
    }
}
