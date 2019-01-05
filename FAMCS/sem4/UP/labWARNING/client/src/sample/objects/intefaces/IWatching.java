package sample.objects.intefaces;

import java.rmi.Remote;
import java.rmi.RemoteException;


public interface IWatching extends Remote {
    String show() throws RemoteException;
}
