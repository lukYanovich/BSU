package B.start;

import B.entities.Sentence;
import B.entities.Symbol;
import B.entities.Word;

import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static void _print(List<Sentence> arr, BufferedWriter out) throws IOException {
        for (Sentence sentence : arr) {
            int words_count = sentence.words.size();
            for (int j = 0; j < words_count; j++) {
                int word_size = sentence.words.get(j).symbols.size();
                for (int k = 0; k < word_size; k++) {
                    Character ch = sentence.words.get(j).symbols.get(k).element;
                    out.write(ch);
                }
                if (j < words_count - 1)
                    out.write(" ");
            }
            out.write(".\n");
        }
        out.write("\n\n");
    }


    private static List<Sentence> _text_to_arr_sentences(String text) {
        List<Sentence> arr = new ArrayList<>();
        for (String text_sentence : text.split("\\.")) {
            Sentence sentence = new Sentence();
            for (String text_word : text_sentence.split(" ")) {
                if (text_word.equals(""))
                    continue;
                Word word = new Word();
                for (int i = 0; i < text_word.length(); i++) {
                    Symbol s = new Symbol(text_word.charAt(i));
                    word.symbols.add(s);
                }
                sentence.words.add(word);
            }
            arr.add(sentence);
        }
        return arr;
    }


    public static void main(String[] args) {
        String file_in = "C:\\Projects\\MMF\\4sem\\java\\lab7\\src\\B\\resources\\input.txt";
        String file_out = "C:\\Projects\\MMF\\4sem\\java\\lab7\\src\\B\\resources\\output.txt";
        try (
                Scanner _in = new Scanner(System.in);
                BufferedReader in = new BufferedReader(new FileReader(file_in));
                BufferedWriter out = new BufferedWriter(new FileWriter(file_out));
        ) {
            System.out.print("введите символ: ");
            Symbol.main_symbol = _in.next().charAt(0);
            String str = in.readLine();
            StringBuilder text = new StringBuilder();
            while (str != null) {
                text.append(str);
                str = in.readLine();
            }
            List<Sentence> arr = _text_to_arr_sentences(text.toString());
            _print(arr, out);
            List<Word> list_words = new ArrayList<>();
            for (Sentence sentence : arr)
                list_words.addAll(sentence.words);
            list_words.sort(new Comparator<Word>() {
                @Override
                public int compare(Word o1, Word o2) {
                    return o1.compareTo(o2);
                }
            });
            Sentence sentence = new Sentence();
            sentence.words = list_words;
            arr.clear();
            arr.add(sentence);
            _print(arr, out);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
