package B.entities;

import java.util.ArrayList;
import java.util.List;

public class Word implements Comparable<Word> {
    public List<Symbol> symbols;


    public Word() {
        symbols = new ArrayList<>();
    }

    @Override
    public int compareTo(Word o) {
        //-1: первый раньше второго
        Integer count1 = 0, count2 = 0;
        StringBuilder word1 = new StringBuilder();
        StringBuilder word2 = new StringBuilder();
        for (Symbol s : this.symbols) {
            word1.append(s.element);
            if (s.element.equals(Symbol.main_symbol))
                count1++;
        }
        for (Symbol s : o.symbols) {
            word2.append(s.element);
            if (s.element.equals(Symbol.main_symbol))
                count2++;
        }
        if (count1.equals(count2))
            return word1.toString().compareTo(word2.toString());
        else
            return -count1.compareTo(count2);
    }
}
