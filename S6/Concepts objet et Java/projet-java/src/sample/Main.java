package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import lucasdavid.tv.Channel;
import lucasdavid.tv.TV;
import lucasdavid.tv.programs.EnumCSA;
import lucasdavid.xml.XMLParser;
import lucasdavid.xml.element.Element;
import lucasdavid.xml.element.SimpleElement;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Set;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("Hello World");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
    }

    public static void main(String[] args) throws Exception {
        launch(args);
    }
}
