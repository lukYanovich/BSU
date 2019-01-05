package sample.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import sample.objects.IWatchingImpl;
import sample.objects.PrimitiveSUBD;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.io.IOException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;


public class Controller {

    @FXML
    private TextArea textArea;

    @FXML
    private TextField textField;


    public void pushBottonAdd(ActionEvent actionEvent) {
        String temp = textArea.getText() + textField.getText() + "\n";
        textArea.setText(temp);
        textField.clear();

        PrimitiveSUBD.update(temp);
    }


    public void pushClear(ActionEvent actionEvent) {
        textArea.clear();
        PrimitiveSUBD.refresh();
    }


    public void pushExit(ActionEvent actionEvent) {
        PrimitiveSUBD.close();
        System.exit(0);
    }


    @FXML
    public void initialize() throws NamingException, IOException {
        textArea.setEditable(false);
        textArea.setText(PrimitiveSUBD.load());

        Registry stReg = LocateRegistry.createRegistry(Registry.REGISTRY_PORT);

        //контекст, который будет всё нам иницилизировать rmi
        Context context = new InitialContext();

        //протокол - хост - порт - имя приложения
        //"bind" - присоединяет. если занят - exception. "rebind" - переподвяжет, старая потухнет
        context.bind("rmi://localhost:1099/iwatch", new IWatchingImpl(textArea));
    }
}
