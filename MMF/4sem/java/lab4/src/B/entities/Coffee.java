package B.entities;

import java.io.Serializable;

public class Coffee implements Serializable {
    enum Status {
        grains //зёрна
        , ground //молотый
        , soluble_in_banks //растворимый в банках
        , soluble_in_packages
    }

    enum Grade {
        india, costa_rica, brazil
    }


    Status _status;
    Grade _grade; //сорт
    int _price;
    int _volume; //объём
    int _weight; //вес


    private static Status _string_to_status(String status) throws Exception {
        switch (status) {
            case "grains":
                return Status.grains;
            case "ground":
                return Status.ground;
            case "banks":
                return Status.soluble_in_banks;
            case "packages":
                return Status.soluble_in_packages;
            default:
                throw new Exception("неопределённый тип кофе");
        }
    }


    static Grade _string_to_grade(String grade) throws Exception {
        switch (grade) {
            case "india":
                return Grade.india;
            case "brazil":
                return Grade.brazil;
            case "costa-rica":
                return Grade.costa_rica;
            default:
                throw new Exception("неопределённый сорт кофе");
        }
    }


    public Coffee(String status, String grade, int price, int volume, int weight) throws Exception {
        this._status = Coffee._string_to_status(status);
        this._grade = Coffee._string_to_grade(grade);
        this._price = price;
        this._volume = volume;
        this._weight = weight;
    }


    @Override
    public String toString() {
        return "Coffee{" +
                "status=" + _status +
                ", grade=" + _grade +
                ", price=" + _price +
                ", volume=" + _volume +
                ", weight=" + _weight +
                '}';
    }
}
