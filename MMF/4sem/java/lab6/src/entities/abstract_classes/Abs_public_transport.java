package entities.abstract_classes;

import entities.interfaces.Int_transport_vehicle;

public abstract class Abs_public_transport implements Int_transport_vehicle {
    private int _volume_of_fuel;
    private int _max_volume_of_fuel;
    private boolean _is_active;
    private boolean _has_damage;
    private int _number_of_passengers;


    public Abs_public_transport(int max_volume_of_fuel) {
        this._volume_of_fuel = 0;
        this._max_volume_of_fuel = max_volume_of_fuel;
        this._number_of_passengers = 0;
        this._is_active = false;
        this._has_damage = false;
    }


    public void add_passengers(int count) {
        this._number_of_passengers += count;
    }


    public void drop_passengers(int count) throws Exception {
        int deemed_number_of_passengers = this._number_of_passengers - count;
        if (deemed_number_of_passengers < 0)
            throw new Exception("нет столько пассажиров в салоне");
        this._number_of_passengers = deemed_number_of_passengers;
    }


    public void drop_all_passengers() {
        this._number_of_passengers = 0;
    }


    public int get_number_of_passengers() {
        return this._number_of_passengers;
    }


    @Override
    public void start() throws Exception {
        if (_has_damage)
            throw new Exception("невохможно завести");
        this._is_active = true;
    }


    @Override
    public void shut_off() {
        this._is_active = false;
    }


    @Override
    public boolean is_active() {
        return this._is_active;
    }


    @Override
    public void refuel(int volume) throws Exception {
        int deemed_volume = this._volume_of_fuel + volume;
        if (deemed_volume > this._max_volume_of_fuel)
            throw new Exception("в баке нет места");
        this._volume_of_fuel = deemed_volume;
    }


    @Override
    public void damaged() {
        this._has_damage = true;
    }


    @Override
    public void repaired() {
        this._has_damage = false;
    }


    @Override
    public boolean has_damage() {
        return this._has_damage;
    }
}
