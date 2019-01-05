package ru.OS.balls.objects;


import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;


public class Ball {

    private double x, y, radius, speed, slowing, angle, x_max, y_max;
    private GraphicsContext graphicsContext;
    private Color color;
    private int flagX = 1, flagY = 1;
    private final int margin = 3;


    public Ball(double x, double y, double radius, double speed, double slowing, double angle, GraphicsContext gc,
                Color color, double x_max, double y_max) {
        this.x = x;
        this.y = y;
        this.radius = radius;
        this.speed = speed;
        this.slowing = slowing;
        this.angle = angle;
        this.graphicsContext = gc;
        this.color = color;
        this.x_max = x_max;
        this.y_max = y_max;

        paint();
    }

    public double getSpeed() {
        return speed;
    }


    public void paint() {
        cleaning();
        changingCoordinates();
        graphicsContext.setFill(color);
        graphicsContext.fillOval(x, y, radius, radius);
    }


    private void cleaning() {
        graphicsContext.setFill(Color.GREEN);
        graphicsContext.fillRect(x - margin, y - margin, radius + margin * 2, radius + margin * 2);
    }


    private void changingCoordinates() {
        if (x < margin || x_max - x - radius < margin)
            flagX *= -1;
        if (y < margin || y_max - y - radius < margin)
            flagY *= -1;
        speed -= slowing;
        x += flagX * speed * Math.cos(angle);
        y += flagY * speed * Math.sin(angle);
    }
}
