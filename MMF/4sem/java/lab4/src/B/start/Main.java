package B.start;

import B.entities.Coffee;
import B.entities.Coffee_truck;
import B.entities.Connector;

import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String file_in = "C:\\Projects\\MMF\\4sem\\java\\lab4\\src\\B\\resources\\input.txt";
        //String file_serialize = "C:\\Projects\\MMF\\4sem\\java\\lab4\\src\\B\\resources\\temp.out";
        Coffee_truck truck;
        int price = 50, volume = 300;
        try (
                Scanner _in = new Scanner(System.in);
                BufferedReader in = new BufferedReader(new FileReader(file_in));
                Connector connector = new Connector();
        ) {
            //System.out.println("введите объём");
            truck = new Coffee_truck(volume);
            String str = in.readLine();
            while (str != null) {
                String[] temp_arr = str.split(" ");
                if (Integer.parseInt(temp_arr[2]) + truck.get_price_amount() > price) {
                    System.err.println("фургон полон");
                    break;
                }
                truck.add_coffee(new Coffee(
                        temp_arr[0]
                        , temp_arr[1]
                        //цена, объём, вес
                        , Integer.parseInt(temp_arr[2])
                        , Integer.parseInt(temp_arr[3])
                        , Integer.parseInt(temp_arr[4])
                ));
                str = in.readLine();
            }
            System.out.println(truck);
            truck.sort_coffee();
            System.out.println(truck);
            System.out.println(truck.find_by_country("india"));
            //сериализация
            System.out.println("\n\nпосле восстановления:");
            //connector.set_truck(truck);
            System.out.println(connector.get_truck());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
