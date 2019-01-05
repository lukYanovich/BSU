package A.entities;

import java.util.ArrayList;
import java.util.List;

public class One_dimensional_array extends MyArray {
    private List<Element> _arr;

    public One_dimensional_array() {
        super();
        _arr = new ArrayList<>();
    }


    @Override
    public boolean equals(Object obj) {
        return this._arr.equals(((One_dimensional_array) obj)._arr);
    }

    @Override
    public void print() {
        System.out.println(this);
    }

    @Override
    public Element get(int index) {
        return this._arr.get(index);
    }

    @Override
    public void set(int index, Element element) {
        this._arr.set(index, element);
    }

    @Override
    public void add(Element element) {
        this._arr.add(element);
    }

    @Override
    public int get_size() {
        return this._arr.size();
    }

    @Override
    public MyArray add_arr(MyArray arr) throws Exception {
        super.add_arr(arr);
        One_dimensional_array temp = new One_dimensional_array();
        for (int i = 0; i < this._arr.size(); i++)
            temp.add(new Element(this._arr.get(i).get_data() + arr.get(i).get_data()));
        return temp;
    }

    @Override
    public MyArray sub_arr(MyArray arr) throws Exception {
        super.sub_arr(arr);
        One_dimensional_array temp = new One_dimensional_array();
        for (int i = 0; i < this._arr.size(); i++)
            temp.add(new Element(this._arr.get(i).get_data() - arr.get(i).get_data()));
        return temp;
    }

    @Override
    public MyArray mul_arr(MyArray arr) throws Exception {
        super.mul_arr(arr);
        One_dimensional_array temp = new One_dimensional_array();
        for (int i = 0; i < this._arr.size(); i++)
            temp.add(new Element(this._arr.get(i).get_data() * arr.get(i).get_data()));
        return temp;
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder("[ ");
        for (Element element : this._arr)
            str.append(element.get_data()).append(" ");
        str.append("]");
        return str.toString();
    }
}
