package sample.objects;

import javafx.scene.control.TextArea;
import sample.objects.intefaces.IWatching;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;


public class IWatchingImpl extends UnicastRemoteObject implements IWatching {
    private TextArea textArea;

    public IWatchingImpl(TextArea textArea) throws RemoteException {
        this.textArea = textArea;
    }

    @Override
    public String show() {
        return textArea.getText();
    }
}
