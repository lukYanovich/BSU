package sample.objects;


import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;


public class PrimitiveSUBD {

    final private static String FILE_NAME = "C:\\Projects\\FAMCS\\sem4\\UP\\labWARNING\\server\\src\\sample\\resources\\data.txt";
    private static StringBuilder data;


    public static String load() throws IOException {
        data = new StringBuilder("");
        List<String> lines = Files.readAllLines(Paths.get(FILE_NAME), StandardCharsets.UTF_8);
        for (String line : lines) {
            data.append(line).append("\n");
        }
        return data.toString();
    }


    public static void close() {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(FILE_NAME))) {
            bw.write(data.toString());
            bw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static void update(String str) {
        refresh();
        data.append(str).append("\n");
    }

    public static void refresh() {
        data = new StringBuilder("");
    }
}
