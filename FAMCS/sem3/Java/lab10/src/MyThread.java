

public class MyThread extends Thread {
    private Main applet = null;
    //private Color backgroundColor = null;

    MyThread(Main a) {
        applet = a;
    }


    @Override
    public void run() {
        while (this.isAlive()) {
            try {
                Thread.sleep(25);
                applet.setAngle(applet.getAngle() + applet.getStep());
                applet.repaint();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
