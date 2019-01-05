package sample.controllers;


import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.stage.DirectoryChooser;
import javafx.stage.Window;
import sample.objects.Finder;

import java.io.File;


public class Controller extends Window {

    @FXML
    private Button begin;
    @FXML
    private TextField templateOfFile;
    @FXML
    private TextField lineInFile;
    @FXML
    private TextField priorityFind;
    @FXML
    private TextArea resultOfFind;


    private File selectedDirectory = null;


    public void pushChooseDirectory(ActionEvent actionEvent) {
        DirectoryChooser chooser = new DirectoryChooser();
        chooser.setTitle("выбор папки");
        File defaultDirectory = new File("C:/D");
        chooser.setInitialDirectory(defaultDirectory);
        selectedDirectory = chooser.showDialog(this);
    }


    public void pushBegin(ActionEvent actionEvent) {
        if(!begin.isDisable()) {
            Finder f = new Finder(selectedDirectory, templateOfFile.getText(), lineInFile.getText(), resultOfFind);
            if (!priorityFind.getText().equals(""))
                f.setPriority(Integer.parseInt(priorityFind.getText()));
            f.start();
            begin.setDisable(true);
        }
    }


    public void pushClearOut(ActionEvent actionEvent) {
        resultOfFind.clear();
    }
}
