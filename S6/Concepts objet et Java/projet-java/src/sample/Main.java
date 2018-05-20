package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import lucasdavid.tv.TV;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("Hello World");
        primaryStage.setScene(new Scene(root));
        primaryStage.show();
        TV tv = new TV();
        tv.load("tvguide_20180430_20180511.xml");
    }

    public static void main(String[] args) throws Exception {
        TV tv = new TV();
        tv.load("tvguide_20180430_20180511.xml");
        // launch(args);
    }
}
