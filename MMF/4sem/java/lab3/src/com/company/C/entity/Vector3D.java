package com.company.C.entity;

import java.math.BigDecimal;

public class Vector3D {
    private int _x1;
    private int _x2;
    private int _x3;

    public Vector3D(int a, int b, int c) {
        this._x1 = a;
        this._x2 = b;
        this._x3 = c;
    }


    public boolean is_orthogonal(Vector3D v) {
        return (this._x1 * v._x1 + this._x2 * v._x2 + this._x3 * v._x3 == 0);
    }


    public boolean is_intersect(Vector3D v) throws Exception {
        if (this.is_orthogonal(v))
            throw new Exception("ортогональные вектора");
        BigDecimal x1 = new BigDecimal((double) this._x1 / v._x1);
        BigDecimal x2 = new BigDecimal((double) this._x2 / v._x2);
        BigDecimal x3 = new BigDecimal((double) this._x3 / v._x3);
        return x1.equals(x2) && x1.equals(x3);
    }


    public boolean is_coplanar(Vector3D b, Vector3D c) {
        int det = this._x1 * (b._x2 * c._x3 - b._x3 * c._x2);
        det -= this._x2 * (b._x1 * c._x3 - b._x3 * c._x1);
        det += this._x3 * (b._x1 * c._x2 - b._x2 * c._x1);
        return det==0;
    }


    @Override
    public String toString() {
        return "(" + _x1 + ", " + _x2 + ", " + _x3 + ")";
    }


    public int get_x1() {
        return _x1;
    }

    public void set_x1(int _x1) {
        this._x1 = _x1;
    }

    public int get_x2() {
        return _x2;
    }

    public void set_x2(int _x2) {
        this._x2 = _x2;
    }

    public int get_x3() {
        return _x3;
    }

    public void set_x3(int _x3) {
        this._x3 = _x3;
    }
}
