package sample.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.canvas.Canvas;
import javafx.scene.control.Button;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.stage.Window;
import sample.resources.MyCircle;
import sample.resources.MyThread;

import java.net.URL;
import java.util.ResourceBundle;


public class Controller extends Window implements Initializable {

    @FXML
    private Canvas canvas;
    @FXML
    private Button button;

    private final double radius = 100;
    private final double borderW = 10;
    private final Color borderColor = Color.BLACK;
    private final Color innerColor = Color.GOLD;

    private MyThread t = null;
    private Stage stage;


    public void setStage(Stage stage){
        this.stage=stage;
    }


    @FXML
    public void begin(ActionEvent actionEvent) {
        if (button.isDisable())
            return;
        button.setDisable(true);
        t.start();
    }


    @Override
    public void initialize(URL location, ResourceBundle resources) {
        MyCircle myCircle = new MyCircle(canvas, radius, borderW, borderColor, innerColor);
        t = new MyThread(myCircle);
        t.setPriority(Thread.MAX_PRIORITY);
    }



}
