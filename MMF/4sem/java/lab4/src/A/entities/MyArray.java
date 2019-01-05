package A.entities;

abstract public class MyArray {
    private static int count = 10;
    private int number;


    public abstract void print();

    public abstract Element get(int index);

    public abstract void set(int index, Element element);

    public abstract void add(Element element);

    public abstract int get_size();

    private void _check(MyArray arr) throws Exception {
        if (this.get_size() != arr.get_size())
            throw new Exception("массивы разных размеров");
    }

    public MyArray add_arr(MyArray arr) throws Exception {
        _check(arr);
        return this;
    }

    public MyArray sub_arr(MyArray arr) throws Exception {
        _check(arr);
        return this;
    }

    public MyArray mul_arr(MyArray arr) throws Exception {
        _check(arr);
        return this;
    }

    public MyArray() {
        this.number = count++;
    }

    @Override
    public int hashCode() {
        return this.number;
    }
}
