package A.library.entities;

public class Book {
    int _id;
    String _name;
    String _user;
    boolean _read_on_room_only;


    public Book(int id, String name, boolean read_on_room_only) {
        this._id = id;
        this._name = name;
        this._user = "";
        this._read_on_room_only = read_on_room_only;
    }


    void take_book(String user) {
        this._user = user;
    }


    void return_book() {
        this._user = "";
    }
}
