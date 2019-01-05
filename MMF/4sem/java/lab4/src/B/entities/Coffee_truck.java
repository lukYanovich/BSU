package B.entities;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Coffee_truck implements Serializable {
    private int _volume_amount;
    int _max_volume;
    private int _price_amount;
    List<Coffee> _list;


    public Coffee_truck(int max_volume) {
        _list = new ArrayList<>();
        this._price_amount = 0;
        this._volume_amount = 0;
        this._max_volume = max_volume;
    }


    public void add_coffee(Coffee coffee) throws Exception {
        int deemed_volume = coffee._volume + this._volume_amount;
        if (deemed_volume > this._max_volume)
            throw new Exception("фургон заполнен");
        this._list.add(coffee);
        this._volume_amount = deemed_volume;
        this._price_amount += coffee._price;
    }


    public void sort_coffee() {
        this._list.sort(new Comparator<Coffee>() {
            @Override
            public int compare(Coffee o1, Coffee o2) {
                BigDecimal ue1 = new BigDecimal((double) o1._weight / o1._price);
                BigDecimal ue2 = new BigDecimal((double) o2._weight / o2._price);
                return -ue1.compareTo(ue2);
            }
        });
    }


    public List<Coffee> find_by_country(String country) throws Exception {
        List<Coffee> temp_list = new ArrayList<>();
        Coffee.Grade grade = Coffee._string_to_grade(country);
        for (Coffee coffee : _list)
            if (coffee._grade == grade)
                temp_list.add(coffee);
        return temp_list;
    }


    public int get_price_amount() {
        return this._price_amount;
    }


    @Override
    public String toString() {
        StringBuilder str = new StringBuilder("Coffee_truck{" +
                "_volume_amount=" + _volume_amount +
                ", _max_volume=" + _max_volume +
                ", _price_amount=" + _price_amount +
                ", _list_coffees=\n");
        for (Coffee coffee : _list)
            str.append("    ").append(coffee).append("\n");
        return str.toString();
    }
}
