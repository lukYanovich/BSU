package entities;

import entities.abstract_classes.Abs_public_transport;

public class Tram extends Abs_public_transport {
    private int _number_of_route;


    public Tram(int max_volume_of_fuel) {
        super(max_volume_of_fuel);
        this._number_of_route = 0;
    }


    public void go_to_depot() {
        this.drop_all_passengers();
        this.shut_off();
    }


    public void go_to_route(int route) throws Exception {
        if (!this.is_active())
            this.start();
        this._number_of_route = route;
    }


    public int get_number_of_route() {
        return this._number_of_route;
    }
}
