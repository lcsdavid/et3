package sample;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;

import javafx.scene.Node;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.ListView;
import javafx.scene.layout.HBox;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;


public class Controller implements Initializable {
    public Controller() throws IOException {}

    private Node channelSearchTool = FXMLLoader.load(getClass().getResource("channel/channelSearchBarSample.fxml"));
    private Node programSearchTool = FXMLLoader.load(getClass().getResource("program_searchtool_sample.fxml"));

    @FXML
    private HBox searchHBox;
    @FXML
    private ChoiceBox<String> choiceBox;

    @FXML
    ListView<HBox> listView;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        choiceBox.getSelectionModel().selectedIndexProperty().addListener((observable, oldValue, newValue) -> {
            if (searchHBox.getChildren().size() > 1)
                searchHBox.getChildren().remove(1);
            switch (newValue.intValue()) {
                case 0:
                    break;
                case 1:
                    searchHBox.getChildren().add(channelSearchTool);
                    break;
                case 2:
                    searchHBox.getChildren().add(programSearchTool);
                    break;
                case 3:
                    break;
                default:
                    break;
            }
        });
        choiceBox.setItems(FXCollections.observableArrayList("", "chaînes", "programmes", "contributeurs"));
    }
}
