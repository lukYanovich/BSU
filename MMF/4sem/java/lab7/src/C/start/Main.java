package C.start;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static String getBWT(String text) {
        int length = text.length();
        String []removes = new String[length];
        String bwtext = "";
        int findex = 0;

        removes[0] = text;
        int index = 1;
        while(index != length){
            removes[index] = removes[index - 1].substring(1) + removes[index - 1].charAt(0);
            index++;
        }

        Arrays.sort(removes);

        findex = Arrays.asList(removes).indexOf(text);


        for(int i = 0; i < removes.length; i++)
            bwtext += removes[i].charAt(length-1);

        return bwtext + findex;
    }


    private static String reverseBWT(String bwtext, int index) {

        char[] chars = bwtext.toCharArray();
        Arrays.sort(chars);
        String sbwtext = new String(chars);

        String []removes = new String[bwtext.length()];
        String []buffer = new String[bwtext.length()];

        for(int k=0; k< bwtext.length(); k++){
            removes[k] = Character.toString(bwtext.charAt(k));
            buffer[k] = Character.toString(sbwtext.charAt(k));
        }

        for(int j=0; j < bwtext.length()-1;j++) {
            for (int i = 0; i < bwtext.length(); i++) {
                removes[i] += buffer[i].charAt(buffer[i].length()-1);
                buffer[i] = removes[i];

            }
            Arrays.sort(buffer);
        }

        return  buffer[index];
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Введите текст:");
        String text = sc.nextLine();

        String bwtext = getBWT(text);
        System.out.println("Форма Барроуза-Уилера:" + bwtext.substring(0, text.length()));
        System.out.println("Обратное преобразование:"+reverseBWT(bwtext.substring(0, text.length()),
                Integer.parseInt(Character.toString(bwtext.charAt(bwtext.length()-1)))));
    }
}

