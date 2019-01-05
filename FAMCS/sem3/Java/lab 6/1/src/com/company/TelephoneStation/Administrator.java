package com.company.TelephoneStation;

import java.io.Serializable;
import java.util.Set;
import java.util.TreeSet;

/**
 * Created by Александр on 24.10.2016.
 */

//админов много, но работают с одной базой данных
public class Administrator implements Serializable {

    private static final long serialVersionUID = 1L;
    private String surname;
    private String name;
    private static Set<Subscriber> listOfClients = new TreeSet<>();
    private static final int priseOfSERVICE_1 = 1;
    private static final int priseOfSERVICE_2 = 2;


    private static final int priseOfOneMinuteTalking = 1;

    public enum Services {SERVICES_1, SERVICES_2}


    public Administrator(String surname, String name) {
        this.surname = surname;
        this.name = name;
    }


    static void addClient(Subscriber client) throws Exception {
        if (!listOfClients.add(client))
            throw new Exception("ошибка добавления абонента в listOfClients. " +
                    "вероятно, номер занят");
    }


    private static boolean hasSERVISE_1(Subscriber client) {
        return client.getServices().contains(Administrator.Services.SERVICES_1);
    }

    private static boolean hasSERVISE_2(Subscriber client) {
        return client.getServices().contains(Administrator.Services.SERVICES_2);
    }

    private static void checkContainsAndStatusOfActivity(Subscriber client) throws Exception {
        if (!listOfClients.contains(client))
            throw new Exception("неверный запрос: такого абонента нет в списке");
        if (client.getMoneyOnAccount() < 1)
            throw new Exception("нельзя выполнить звонок: недостаточно средств на счёте");
    }


    static void talk(Subscriber client, int mitunes) throws Exception {
        checkContainsAndStatusOfActivity(client);
        listOfClients.remove(client);
        if (hasSERVISE_1(client) && hasSERVISE_2(client))
            client.setMoneyOnAccount(client.getMoneyOnAccount()
                    - (priseOfSERVICE_1 + priseOfSERVICE_2 + priseOfOneMinuteTalking) * mitunes);
        else if (hasSERVISE_1(client))
            client.setMoneyOnAccount(client.getMoneyOnAccount()
                    - (priseOfSERVICE_1 + priseOfOneMinuteTalking) * mitunes);
        else if (hasSERVISE_2(client))
            client.setMoneyOnAccount(client.getMoneyOnAccount()
                    - (priseOfSERVICE_2 + priseOfOneMinuteTalking) * mitunes);
        else
            client.setMoneyOnAccount(client.getMoneyOnAccount() - priseOfOneMinuteTalking * mitunes);
        listOfClients.add(client);
    }


    static void replenishTheBankAccount(Subscriber client, int amount) throws Exception {
        if (!listOfClients.contains(client))
            throw new Exception("неверный запрос: такого абонента нет в списке");
        listOfClients.remove(client);
        client.setMoneyOnAccount(client.getMoneyOnAccount() + amount);
        listOfClients.add(client);
    }


    void changeNumber(Subscriber client, int number) throws Exception {
        checkContainsAndStatusOfActivity(client);
        if (number > 1000 || number < 100)
            throw new Exception("неверный номер");
        listOfClients.remove(client);
        client.setNumber(number);
        listOfClients.add(client);
    }


    boolean deleteServise(Subscriber client, Services services) throws Exception {
        checkContainsAndStatusOfActivity(client);
        if (services == Services.SERVICES_1)
            if (!hasSERVISE_1(client))
                return false;
            else {
                listOfClients.remove(client);
                TreeSet<Services> temp = client.getServices();
                temp.remove(services);
                client.setServices(temp);
                listOfClients.add(client);
                return true;
            }
        else {
            if (!hasSERVISE_2(client))
                return false;
            else {
                listOfClients.remove(client);
                TreeSet<Services> temp = client.getServices();
                temp.remove(services);
                client.setServices(temp);
                listOfClients.add(client);
                return true;
            }
        }
    }


    public static String printListOfClients() {
        String temp = "";
        for (Subscriber i : listOfClients)
            temp = temp + i + '\n';
        return temp;
    }


    @Override
    public String toString() {
        return "Administrator{" +
                "surname='" + surname + '\'' +
                ", name='" + name + '\'' +
                '}';
    }
}
