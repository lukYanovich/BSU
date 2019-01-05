package C.entities;

public class Person {
    private String _fio;
    private String _phone_number;


    public Person(String fio, String phone_number) {
        this._fio = fio;
        this._phone_number = phone_number;
    }


    public String print_to_file() {
        return this._fio + ";" + this._phone_number + "\n";
    }


    public String get_phone_number() {
        return _phone_number;
    }
}
