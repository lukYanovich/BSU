package B.entities;

import java.io.*;

public class Connector extends Thread implements Closeable {
    private Coffee_truck _truck;
    private static final String filename="C:\\Projects\\MMF\\4sem\\java\\lab4\\src\\B\\resources\\temp.out";
    private static final File file_serialize = new File(filename);


    public Connector() {
        try (ObjectInputStream oin = new ObjectInputStream(new FileInputStream(file_serialize))) {
            synchronized (file_serialize) {
                this._truck = (Coffee_truck) oin.readObject();
            }
            this.start();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }


    public void add_coffee(Coffee coffee) {
        this._truck._list.add(coffee);
    }


    public void remove_coffee(Coffee coffee) {
        this._truck._list.remove(coffee);
    }


    public Coffee_truck get_truck() {
        return _truck;
    }


    public void set_truck(Coffee_truck truck) {
        this._truck = truck;
    }


    @Override
    public void run() {
        try (ObjectInputStream oin = new ObjectInputStream(new FileInputStream(file_serialize))) {
            while (!this.isInterrupted()) {
                Coffee_truck truck;
                synchronized (file_serialize) {
                    truck = (Coffee_truck) oin.readObject();
                }
                if (!this._truck.equals(truck)) {
                    this._truck = truck;
                }
            }
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }


    @Override
    public void close() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(file_serialize))) {
            synchronized (file_serialize) {
                oos.writeObject(this._truck);
                oos.flush();
            }
        }
        catch (IOException e){
            e.printStackTrace();
        }
    }
}
