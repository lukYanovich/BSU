package com.company.TelephoneStation;

import com.company.support.LocaleAPI;

import java.io.Serializable;
import java.text.DateFormat;
import java.util.Date;
import java.util.TreeSet;

/**
 * Created by Александр on 24.10.2016.
 */

//отправляют запросы админу, который проверяет возможность
//выполнения согласно базе данных
    //номера трёхзначные
public class Subscriber implements Serializable, Comparable<Subscriber> {

    private static final long serialVersionUID = 1L;
    private String surname;
    private String name;
    private Integer number;
    private Integer moneyOnAccount;
    private TreeSet<Administrator.Services> services = new TreeSet<>();

    private final Date creationDate = new Date();

    public String getCreationDate() {
        DateFormat dateFormatter = DateFormat.getDateTimeInstance(
                DateFormat.DEFAULT, DateFormat.DEFAULT, LocaleAPI.get());
        String dateOut = dateFormatter.format(creationDate);
        return dateOut;
    }


    public Subscriber(String surname, String name, int number) throws Exception {
        if (number > 1000 || number < 100)
            throw new Exception("неверный номер");

        this.surname = surname;
        this.name = name;
        this.number = number;
        this.moneyOnAccount = 50;
        services.add(Administrator.Services.SERVICES_1);
        services.add(Administrator.Services.SERVICES_2);
        Administrator.addClient(this);
    }


    public void talkingOnThePhone(int minutes) throws Exception {
        Administrator.talk(this, minutes);
    }


    public boolean deleteServices(Administrator admin, Administrator.Services serv) throws Exception {
        return admin.deleteServise(this, serv);
    }


    public void replenishTheBankAccount(int amountOfMoney) throws Exception {
        Administrator.replenishTheBankAccount(this, amountOfMoney);
    }


    public void changeNumber(Administrator admin, int newNumber) throws Exception {
        admin.changeNumber(this, newNumber);
    }


    public String getSurname() {
        return surname;
    }

    public String getName() {
        return name;
    }

    public Integer getNumber() {
        return number;
    }

    public int getMoneyOnAccount() {
        return moneyOnAccount;
    }

    void setMoneyOnAccount(int moneyOnAccount) {
        this.moneyOnAccount = moneyOnAccount;
    }

    @Override
    public int compareTo(Subscriber o) {
        return Integer.compare(this.number, o.number);
    }

    TreeSet<Administrator.Services> getServices() {
        return services;
    }

    void setServices(TreeSet<Administrator.Services> services) {
        this.services = services;
    }

    @Override
    public String toString() {
        return  LocaleAPI.getString(LocaleAPI.subscriber) + ": { " +
                LocaleAPI.getString(LocaleAPI.surname) + " = \"" + surname + "\", " +
                LocaleAPI.getString(LocaleAPI.name) + " = \"" + name + "\", " +
                LocaleAPI.getString(LocaleAPI.number) + " = \"" + number + "\", " +
                LocaleAPI.getString(LocaleAPI.moneyOnAccount) + " = \"" + moneyOnAccount + "\", " +
                LocaleAPI.getString(LocaleAPI.services) + " = " + services +
                " }";
    }

    void setNumber(Integer number) {
        this.number = number;
    }
}
