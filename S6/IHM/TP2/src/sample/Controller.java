package sample;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;

import javafx.scene.control.*;
import javafx.scene.image.ImageView;
import tree.Tree;

import java.io.File;
import java.net.URL;
import java.util.ResourceBundle;

public class Controller implements Initializable {
    private static ImageView dirIcon;
    private static ImageView hiddenDirIcon = new ImageView();
    private static ImageView fileIcon = new ImageView();

    private FileSelector fileSelector;

    @FXML
    private TextField pathSelector;

    @FXML
    private TreeView<String> fileView;

    @FXML
    private void open() {

    }

    @FXML
    private void cancel() {
        System.exit(0);
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        /* */
        System.out.println(new File("rsc/dirIcon.jpg").getAbsolutePath());
        /* initialize values */
        pathSelector.setText(new File("").getAbsolutePath());
        fileSelector = new FileSelector(fileView);
        fileSelector.initialize();
        TreeItem<String> current = fileSelector.insert(new File("").getAbsolutePath());
        fileSelector.expand(current);
        fileSelector.select(current);
        /**/
        /**/

    }



}
