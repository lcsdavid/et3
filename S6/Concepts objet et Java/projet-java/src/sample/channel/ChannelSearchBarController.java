package sample.channel;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ChoiceBox;

import java.net.URL;
import java.util.ResourceBundle;

public class ChannelSearchBarController implements Initializable {
    @FXML
    private ChoiceBox<String> orderBySelector;

    private void modifyList() {

    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        orderBySelector.setItems(FXCollections.observableArrayList("", ""));
    }
}
