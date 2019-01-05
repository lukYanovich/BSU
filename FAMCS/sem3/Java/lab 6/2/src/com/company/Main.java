package com.company;

import com.company.TelephoneStation.Administrator;
import com.company.TelephoneStation.Subscriber;
import com.company.support.Connector;
import com.company.support.LocaleAPI;

import java.util.Arrays;
import java.util.Locale;

public class Main {

    public static void main(String[] args) throws Exception {
        // write your code here
        try {
            String language = args[0];
            //String country = args[1];
            Locale loc = new Locale(language);
            LocaleAPI.set(loc);


            Administrator adm = new Administrator("Иванов", "Сергей");
            Subscriber s1 = new Subscriber("Щёголев", "Антон", 574);
            Subscriber s2 = new Subscriber("Тарасов", "Пётр", 573);
            Subscriber s3 = new Subscriber("Лось", "Олег", 173);
            s2.talkingOnThePhone(10);
            s1.deleteServices(adm, Administrator.Services.SERVICES_2);
            s2.deleteServices(adm, Administrator.Services.SERVICES_1);
            s1.talkingOnThePhone(50);
            s2.changeNumber(adm, 300);
            s3.replenishTheBankAccount(100);
            System.out.println(Administrator.printListOfClients());

            Subscriber[] arr = {s1, s2, s3};
            Arrays.sort(arr);

            Connector con = new Connector("temp.dat");
            con.write(arr);
            arr = con.read();
            for (Subscriber i : arr)
                System.out.println(i);
        } catch (Throwable e) {
            System.err.println(e);
        }
    }
}
