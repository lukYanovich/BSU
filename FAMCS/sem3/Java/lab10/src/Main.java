/**
 * Created with IntelliJ IDEA.
 * Author:
 * Date  : 27/02/13
 * Time  : 9:50 AM
 */
import java.applet.Applet;
import java.awt.*;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import java.util.TreeSet;


public class Main extends Applet {
    private int x1, y1, x2, y2, x3, y3, x, y;
    private Color triangleColor;
    private double angle = 0;
    private final double step = Math.PI / 90.0;
    private MyThread t  = null;


    public void init() {
        try {
            String[] temp = this.getParameter("backgroundColor").split(" ");
            Color backgroundColor = new Color(
                    Integer.parseInt(temp[0]),
                    Integer.parseInt(temp[1]),
                    Integer.parseInt(temp[2])
            );
            setBackground(backgroundColor);

            temp = this.getParameter("triangleColor").split(" ");
            triangleColor = new Color(
                    Integer.parseInt(temp[0]),
                    Integer.parseInt(temp[1]),
                    Integer.parseInt(temp[2])
            );

            temp = this.getParameter("point1").split(" ");
            x1 = Integer.parseInt(temp[0]);
            y1 = Integer.parseInt(temp[1]);

            temp = this.getParameter("point2").split(" ");
            x2 = Integer.parseInt(temp[0]);
            y2 = Integer.parseInt(temp[1]);

            temp = this.getParameter("point3").split(" ");
            x3 = Integer.parseInt(temp[0]);
            y3 = Integer.parseInt(temp[1]);

            if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x1 == x3 && y1 == y3))
                throw new Exception("неверные парметры точек");

            x = (x1 + x2 + x3) / 3;
            y = (y1 + y2 + y3) / 3;
        } catch (Exception e) {
            System.err.println(e);
            e.printStackTrace();
        }
    }


    public void start() {
        if (t == null)
            t = new MyThread(this);
        t.start();
    }


    private void stopThread() {
        if (t != null) {
            t.interrupt();
            t = null;
        }
    }


    public void update(Graphics g) {
        int[] arrayX = {x1, x2, x3, x1};
        int[] arrayY = {y1, y2, y3, y1};

        Image buffer = new BufferedImage(getWidth(), getHeight(), BufferedImage.TYPE_3BYTE_BGR);
        Graphics2D gr = (Graphics2D) buffer.getGraphics();
        AffineTransform at = AffineTransform.getRotateInstance(angle, x, y);
        gr.setTransform(at);

        int rad = (int) (0.5 * Math.sqrt(getHeight() * getHeight() + getWidth() * getWidth())) + 1;
        gr.setColor(this.getBackground());
        TreeSet<Color> three = new TreeSet<Color>();
        gr.fillOval(-rad / 2, -rad, 3 * rad, 3 * rad);
        gr.setColor(Color.BLACK);
        Polygon poly = new Polygon(arrayX, arrayY, arrayX.length);
        gr.drawPolygon(poly);
        gr.setColor(triangleColor);
        gr.fillPolygon(poly);

        g.drawImage(buffer, 0, 0, this);
    }


    public void paint(Graphics g) {
        update(g);
    }

    public void stop() {
        stopThread();
    }

    public void destroy() {
        stopThread();
    }

    public void setAngle(double angle) {
        this.angle = angle;
    }

    public double getAngle() {
        return angle;
    }

    public double getStep() {
        return step;
    }
}
