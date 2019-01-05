package start;

import entities.Tram;

public class Main {
    public static void main(String[] args) {
        try {
            Tram t = new Tram(20);
            t.refuel(15);
            t.go_to_route(5);
            System.out.println(t.get_number_of_route());
            System.out.println(t.is_active());
            //t.refuel(10);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
