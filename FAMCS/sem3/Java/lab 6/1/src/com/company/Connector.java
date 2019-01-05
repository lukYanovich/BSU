package com.company;

import com.company.TelephoneStation.Subscriber;

import java.io.*;

/**
 * Created by Александр on 27.10.2016.
 */

public class Connector {
    private String filename;

    public Connector(String filename) {
        this.filename = filename;
    }


    public void write(Subscriber[] clients) throws IOException {
        FileOutputStream fos = new FileOutputStream(filename);
        try (ObjectOutputStream oos = new ObjectOutputStream(fos)) {
            oos.writeInt(clients.length);
            for (int i = 0; i < clients.length; i++) {
                oos.writeObject(clients[i]);
            }
            oos.flush();
        }
    }


    public Subscriber[] read() throws IOException, ClassNotFoundException {
        FileInputStream fis = new FileInputStream(filename);
        try (ObjectInputStream oin = new ObjectInputStream(fis)) {
            int length = oin.readInt();
            Subscriber[] result = new Subscriber[length];
            for (int i = 0; i < length; i++) {
                result[i] = (Subscriber) oin.readObject();
            }
            return result;
        }
    }
}
