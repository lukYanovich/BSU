package AB.start;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

/**
 * <pre>
 * класс {@link Main} является корневым для этого задания.
 * при запуске вызывается метод {@link Main#main} и начинается магия
 *
 * считываем из файла числа и ищем наименьшее и наибольшее по количеству символов
 *
 * проект получен в феврале
 * проект сдаётся: <script>
  var d = new Date();

  var day=new Array("Воскресенье","Понедельник","Вторник",
  "Среда","Четверг","Пятница","Суббота");

  var month=new Array("января","февраля","марта","апреля","мая","июня",
  "июля","августа","сентября","октября","ноября","декабря");

  document.write(day[d.getDay()]+" " +d.getDate()+ " " + month[d.getMonth()]
  + " " + d.getFullYear() + " г.");
 </script>
 *
 * @author Александр
 * </pre>
 */

public class Main {
    public static void main(String[] args) {
        String filename = "C:\\Projects\\MMF\\4sem\\java\\lab2\\src\\com\\company\\resources\\input.txt";
        List<String> arr = new ArrayList<>();
        try (BufferedReader in = new BufferedReader(new FileReader(filename))) {
            String str = in.readLine();
            while (str != null) {
                arr.addAll(Arrays.asList(str.split(" ")));
                str = in.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        arr.sort(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.length() - o2.length();
            }
        });
        System.out.println("самое короткое: " + arr.get(0) + ", длинна: " + arr.get(0).length());
        System.out.println("самое длинное: " + arr.get(arr.size() - 1) + ", длинна: " + arr.get(arr.size() - 1).length());
    }
}
