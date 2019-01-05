package sample.resources;

import javafx.scene.transform.Affine;

public class MyThread extends Thread {

    private MyCircle circle = null;


    public MyThread(MyCircle myCircle) {
        this.circle = myCircle;
    }


    private void setAffine(double h) {
        setAffine(h, 0);
    }


    private void setAffine(double hx, double hy) {
        Affine af = new Affine(1, 0, hx, 0, 1, hy);
        circle.setAffineTransform(af);
        try {
            sleep(10);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        circle.repaint();
    }


    @Override
    public void run() {
        int hx = 0;   //смещение
        boolean moveToRigth = true;
        final double minRad = circle.radX / 2, maxRad = circle.radY, incY = 0.01, offsetY = 0.1;

        while (!isInterrupted()) {
            if (moveToRigth == true) {
                //правая стенка: движение вправо и отражение
                if (circle.x + hx + maxRad > circle.getWidth()-circle.getBorderW()) {
                    double hy = 0;
                    while (circle.radX > minRad) {
                        circle.radX--;
                        circle.radY -= incY;
                        hx++;
                        hy += offsetY;
                        setAffine(hx, hy);
                    }
                    while (circle.radX < maxRad) {
                        circle.radX++;
                        circle.radX += incY;
                        hx--;
                        hy -= offsetY;
                        setAffine(hx, hy);
                    }
                    moveToRigth = false;
                    continue;
                }
                setAffine(++hx);
            } else if (moveToRigth == false) {
                //левая стенка: движение влево и отражение
                if (circle.x + hx < circle.getBorderW()) {
                    double hy = 0;
                    while (circle.radX > minRad) {
                        circle.radX--;
                        circle.radY -= incY;
                        hy += offsetY;
                        setAffine(hx, hy);
                    }
                    while (circle.radX < maxRad) {
                        circle.radX++;
                        circle.radY += incY;
                        hy -= offsetY;
                        setAffine(hx, hy);
                    }
                    moveToRigth = true;
                    continue;
                }
                setAffine(--hx);
            }
        }
    }
}
