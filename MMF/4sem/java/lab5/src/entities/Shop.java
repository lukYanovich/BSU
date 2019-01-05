package entities;

import java.util.List;
import java.util.TreeSet;

public class Shop {
    private TreeSet<Department> _list_of_departments;


    public class Department implements Comparable<Department> {
        private List<Product> _list_of_products;
        private String _services;
        private String _department_name;


        @Override
        public int compareTo(Department o) {
            return this._department_name.compareTo(o._department_name);
        }


        class Product {
            private int _price;
            private int _discount;
            private String _name;
        }
    }
}
