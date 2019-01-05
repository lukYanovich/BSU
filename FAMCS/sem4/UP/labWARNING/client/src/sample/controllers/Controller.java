package sample.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextArea;
import sample.objects.intefaces.IWatching;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.rmi.RemoteException;


public class Controller extends Thread {

    private IWatching iWatching;

    @FXML
    TextArea textArea;


    public void pushButton(ActionEvent actionEvent) throws RemoteException {
        refreshTextArea();
    }

    private void refreshTextArea() throws RemoteException {
        textArea.setText(iWatching.show());
    }


    @FXML
    public void initialize() throws NamingException, RemoteException {
        Context context = new InitialContext();

        /*
        //даёт все приложения, которые запущены на хосте
        Enumeration<NameClassPair> e = context.list("rmi://localhost/");
        while (e.hasMoreElements())
            System.out.println(e.nextElement().getName());
        */

        iWatching = (IWatching) context.lookup("rmi://localhost/iwatch");
        this.start();
    }


    @Override
    public void run() {
        while (!isInterrupted()) {
            try {
                refreshTextArea();
            } catch (RemoteException e) {
                e.printStackTrace();
            }
            try {
                sleep(3000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
