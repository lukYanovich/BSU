package client.controllers;


import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Modality;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;
import java.io.IOException;


public class Controller_authorization {
    @FXML
    private TextField _login;


    public void submit_login(ActionEvent actionEvent) {
        if (!this._login.getText().equals("")) {
            try {
                //создание графического окна
                Stage stage = new Stage();
                FXMLLoader loader = new FXMLLoader(getClass().getResource("../fxml/chat.fxml"));
                Parent root = loader.load();
                stage.setTitle("chat");
                stage.setScene(new Scene(root));
                stage.setMinHeight(400);
                stage.setMinWidth(700);
                //устанавливаем модальность
                stage.initModality(Modality.WINDOW_MODAL);
                //устанавливаем родителя
                stage.initOwner(((Node) actionEvent.getSource()).getScene().getWindow());
                //совершаем обмени данными между формами
                Controller_chat controller_chat = loader.getController();
                controller_chat.set_user_name(this._login.getText().toLowerCase());
                controller_chat.start();
                stage.show();
                //событие нажатия на крестик
                stage.setOnCloseRequest(new EventHandler<WindowEvent>() {
                    @Override
                    public void handle(WindowEvent event) {
                        controller_chat.interrupt();
                        controller_chat.close_window();
                    }
                });
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
