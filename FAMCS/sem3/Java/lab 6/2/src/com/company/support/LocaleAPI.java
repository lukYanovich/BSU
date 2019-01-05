package com.company.support;

import java.util.Locale;
import java.util.ResourceBundle;

/**
 * Created by Александр on 27.10.2016.
 */

public class LocaleAPI {
    private static final String strTS = "com.company.bundles.TS";
    private static Locale myLoc = Locale.getDefault();
    private static ResourceBundle rs =
            ResourceBundle.getBundle(LocaleAPI.strTS, LocaleAPI.myLoc);


    public static void set(Locale loc) {
        LocaleAPI.myLoc = loc;
        LocaleAPI.rs = ResourceBundle.getBundle(LocaleAPI.strTS, LocaleAPI.myLoc);
    }

    public static Locale get() {
        return myLoc;
    }

    public static String getString(String key) {
        return LocaleAPI.rs.getString(key);
    }


    //ключи в локалях
    public static final String subscriber = "subscriber";
    public static final String surname = "surname";
    public static final String name = "name";
    public static final String number = "number";
    public static final String moneyOnAccount = "moneyOnAccount";
    public static final String services = "services";
}
