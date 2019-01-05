package ru.OS.balls.controllers;


import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.paint.Color;
import ru.OS.balls.objects.Ball;
import ru.OS.balls.objects.ObserveringThread;

import java.util.Random;


public class MainController {

    private GraphicsContext graphicsContext;
    private Random random = new Random();
    private ObserveringThread t;

    @FXML
    private Button buttonPause;

    @FXML
    private Button buttonReload;

    @FXML
    private Button buttonStop;

    @FXML
    private Button buttonAddBall;

    @FXML
    private Canvas table;

    @FXML
    private TextArea textArea;

    @FXML
    private TextField textField;


    @FXML
    public void initialize() {
        graphicsContext = table.getGraphicsContext2D();
        graphicsContext.setFill(Color.GREEN);
        graphicsContext.fillRect(0, 0, table.getWidth(), table.getHeight());

        t = new ObserveringThread(table);
        t.start();
    }


    public void ButtonClicked(ActionEvent actionEvent) throws InterruptedException {
        Object source = actionEvent.getSource();
        Button clickedButton = (Button) source;

        switch (clickedButton.getId()) {
            case "buttonPause":
                t.pause();
                break;

            case "buttonReload":
                t.reload();
                break;

            case "buttonStop":
                t.stopAll();
                break;

            case "buttonAddBall":
                t.add(createBall());
                break;
        }
    }


    private Ball createBall() {
        int margin = 10;
        double x = 5 * margin + random.nextInt((int) table.getWidth() - 10 * margin);
        double y = 5 * margin + random.nextInt((int) table.getHeight() - 10 * margin);
        double radius = 5 + random.nextInt(4 * margin);
        double speed = 3 + random.nextInt(margin / 2);
        double slowing = random.nextInt(margin) / 50;
        double angle = -margin + random.nextInt(margin);
        int col = random.nextInt(11);
        Color color;
        switch (col) {
            case 0:
                color = Color.RED;
                break;
            case 1:
                color = Color.YELLOW;
                break;
            case 2:
                color = Color.BLUE;
                break;
            case 3:
                color = Color.INDIGO;
                break;
            case 4:
                color = Color.WHITE;
                break;
            case 5:
                color = Color.VIOLET;
                break;
            case 6:
                color = Color.NAVY;
                break;
            case 7:
                color = Color.MAGENTA;
                break;
            case 8:
                color = Color.BISQUE;
                break;
            case 9:
                color = Color.ROSYBROWN;
                break;
            case 10:
                color = Color.GOLDENROD;
                break;
            default:
                color = Color.GREY;
                break;
        }
        return new Ball(x, y, radius, speed, slowing, angle, graphicsContext, color, table.getWidth(), table.getHeight());
    }
}
