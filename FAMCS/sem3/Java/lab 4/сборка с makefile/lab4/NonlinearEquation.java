
import java.util.ArrayList;
import java.util.List;


final public class NonlinearEquation {

    private List<Double> polynom;

    public NonlinearEquation(double[] arr) {
        polynom = new ArrayList<>();
        for (int i = 0; i < arr.length; i++)
            polynom.add(arr[i]);
    }


    public NonlinearEquation(NonlinearEquation a) {
        polynom = new ArrayList<>();
        polynom.addAll(a.polynom);
    }


    public void setRatioByIndex(int index, Double ratio){
        polynom.set(index, ratio);
    }


    private void canonical() {
        if (polynom.get(0) != 1)
            for (int i = 1; i < polynom.size(); i++)
                polynom.set(i, polynom.get(i) / polynom.get(0));
        polynom.set(0, polynom.get(0) / polynom.get(0));
    }


    public String print() throws Exception {
        if (polynom.size() < 2)
            throw new Exception("это не полином");
        canonical();
        String s = "[ ";
        for (int i = 0; i < polynom.size() - 2; i++) {
            if (polynom.get(i) == 0.0)
                continue;
            if (i > 0 && polynom.get(i) > 0)
                s += "+";
            if (polynom.get(i) == 1.0)
                s += "x^" + (polynom.size() - i - 1);
            else
                s += polynom.get(i) + "*x^" + (polynom.size() - i - 1);
        }

        //элемент степени 1 (при х)
        if (polynom.get(polynom.size() - 2) != 0.0) {
            if (polynom.size() == 2)
                s += "x";
            else {
                if (polynom.get(polynom.size() - 2) > 0)
                    s += "+";
                if (polynom.get(polynom.size() - 2) == 1.0)
                    s += "x";
                else
                    s += polynom.get(polynom.size() - 2) + "*x";
            }
        }

        //свободный член (при x^0)
        if (polynom.get(polynom.size() - 1) != 0.0) {
            if (polynom.get(polynom.size() - 1) > 0)
                s += "+";
            s += polynom.get(polynom.size() - 1);
        }
        s += " = 0 ]";
        return s;
    }


    private Double pow(double value, double degree) {
        if (value == 1.0)
            return value;
        else if (degree == 0.0)
            return 1.0;
        return Math.pow(value, degree);
    }


    //подстановка значения в многочлен
    private Double func(Double value) {
        Double temp = new Double(0);
        for (int i = 0; i < polynom.size(); i++)
            temp += polynom.get(i) * pow(value, polynom.size() - 1 - i);
        return temp;
    }


    public Double getSolutionOnInterval(Double a, Double b) throws Exception {
        if (a == b)
            throw new Exception("это не промежуток.");
        if (Math.signum(func(a)) == Math.signum(func(b)))
            throw new Exception("неверный промежуток для бисекции(на нём нет корней).");
        double c = 0, eps = 1e-8;
        while (b - a > 2 * eps) {
            c = (a + b) / 2;
            if (func(c) == 0)
                break;
            if (func(a) * func(c) < 0)
                b = c;
            else
                a = c;
        }
        return c;
    }
}
