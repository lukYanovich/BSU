package ru.OS.balls.objects;

import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;


public class ObserveringThread extends Thread {

    private List<Ball> list = new ArrayList<>();
    private boolean isStoped, isAnimation, firstStart;
    private Canvas table;


    public ObserveringThread(Canvas table) {
        isAnimation = false;
        firstStart = false;
        isStoped = false;
        this.table = table;
    }


    public void add(Ball elem) {
        if (!firstStart) {
            firstStart = isAnimation = true;
        }
        if (list.size() < 4)
            list.add(elem);
    }


    public void pause() {
        isAnimation = false;
    }

    public void reload() {
        isAnimation = true;
    }


    public void stopAll() {
        isAnimation = false;
        isStoped = true;
        firstStart = false;
        list.clear();

        GraphicsContext graphicsContext = table.getGraphicsContext2D();
        graphicsContext.setFill(Color.GREEN);
        graphicsContext.fillRect(0, 0, table.getWidth(), table.getHeight());
    }


    @Override
    public void run() {
        while (!isInterrupted()) {
            for (int i = 0; i < list.size(); i++) {
                if (!isAnimation)
                    break;

                try {
                    if (list.get(i).getSpeed() <= 0)
                        list.remove(i--);
                    else {
                        sleep(100 / (list.size() + 1), 10000 / (list.size() + 1));
                        list.get(i).paint();
                    }
                } catch (Exception e) {
                }
            }

            if (list.isEmpty() && isStoped) {
                messageAlert();
                isAnimation = isStoped = false;
            }
        }
    }


    private void messageAlert() {
        JFrame form = new JFrame("внимание");
        JTextField txt = new JTextField("шары закончили движение");
        form.getContentPane().add(txt);
        form.setVisible(true);
        Dimension dim = new Dimension(200, 200);
        form.setMinimumSize(dim);
        form.setLocationRelativeTo(null);
    }
}
