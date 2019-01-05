package sample.resources;

import com.sun.javafx.geom.PathIterator;
import com.sun.javafx.geom.RectBounds;
import com.sun.javafx.geom.Rectangle;
import com.sun.javafx.geom.Shape;
import com.sun.javafx.geom.transform.BaseTransform;
import javafx.scene.canvas.Canvas;
import javafx.scene.paint.Color;
import javafx.scene.transform.Affine;


public class MyCircle extends Shape {

    private Canvas canvas = null;
    public double x, y, radX, radY;
    private double borderW;


    private Color borderColor, innerColor;


    public MyCircle(Canvas canvas, double rad, double borderW, Color borderColor, Color innerColor) {
        this.canvas = canvas;
        this.x = (canvas.getWidth() - rad) * 0.5;
        this.y = (canvas.getHeight() - rad) * 0.5;
        this.radX = this.radY = rad;
        this.borderW = borderW;
        this.borderColor = borderColor;
        this.innerColor = innerColor;
    }


    public void repaint() {
        canvas.getGraphicsContext2D().clearRect(x - radX, y - radY, x + radX, y + radY);
        canvas.getGraphicsContext2D().setStroke(borderColor);
        canvas.getGraphicsContext2D().setLineWidth(borderW);
        canvas.getGraphicsContext2D().strokeOval(x, y, radX, radY);
        canvas.getGraphicsContext2D().setFill(innerColor);
        canvas.getGraphicsContext2D().fillOval(x, y, radX, radY);
    }


    public double getBorderW() {
        return borderW;
    }

    public void setAffineTransform(Affine at) {
        canvas.getGraphicsContext2D().setTransform(at);
    }

    public double getWidth() {
        return canvas.getWidth();
    }


    @Override
    public RectBounds getBounds() {
        return null;
    }

    @Override
    public boolean contains(float x, float y) {
        return false;
    }

    @Override
    public boolean intersects(float x, float y, float w, float h) {
        return false;
    }

    @Override
    public boolean contains(float x, float y, float w, float h) {
        return false;
    }

    @Override
    public PathIterator getPathIterator(BaseTransform tx) {
        Rectangle rect = new Rectangle((int) x, (int) y, (int) radX, (int) radY);
        return (PathIterator) rect;
    }

    @Override
    public PathIterator getPathIterator(BaseTransform tx, float flatness) {
        return null;
    }

    @Override
    public com.sun.javafx.geom.Shape copy() {
        return null;
    }
}
