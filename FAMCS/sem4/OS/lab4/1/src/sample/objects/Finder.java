package sample.objects;


import javafx.scene.control.TextArea;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Finder extends Thread {

    private File defaultDirectory;
    private String lineInFile;
    private TextArea resultOfFind;
    private String ID;

    private Pattern p = null;


    public Finder(File defaultDirectory, String templateOfFile, String lineInFile, TextArea resultOfFind, String ID) {
        this.defaultDirectory = defaultDirectory;
        this.lineInFile = lineInFile;
        this.resultOfFind = resultOfFind;
        this.ID = ID;

        if (!templateOfFile.equals("")) {
            String temp = templateOfFile.replace(".", "\\.");
            this.p = Pattern.compile("^" + temp.replaceAll("\\*", ".+") + "$");
        }
    }


    @Override
    public void run() {
        search(defaultDirectory, resultOfFind);
    }


    private void workload() {
        for (int i = 0; i < 9999999; i++) {
            double j = Math.cos(1.0);
            double k = Math.sqrt(j);
        }
    }


    private boolean accept(String name) {
        workload();
        if (p == null)
            return true;
        Matcher m = p.matcher(name);
        return m.matches();
    }


    private boolean hasLine(File file) {
        if (lineInFile.equals(""))
            return true;
        try {
            synchronized (file) {
                List<String> lines = Files.readAllLines(Paths.get(file.getAbsolutePath()), StandardCharsets.UTF_8);
                for (String line : lines)
                    if (line.contains(lineInFile))
                        return true;
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }


    private void search(File topDirectory, TextArea res) {
        File[] list = topDirectory.listFiles();
        if (list != null)
            for (File file : list)
                if (file.isDirectory())
                    search(file, res);
                else if (accept(file.getName()) && hasLine(file))
                    synchronized (res) {
                        res.appendText(ID + ":   " + file.getPath() + "\n");
                    }
    }
}
