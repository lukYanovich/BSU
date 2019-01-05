package entities.interfaces;

public interface Int_transport_vehicle {
    void start() throws Exception;

    void shut_off();

    boolean is_active();

    void refuel(int volume) throws Exception;

    void damaged();

    void repaired();

    boolean has_damage();
}