package sample;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;

import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TreeItem;
import javafx.scene.control.TreeView;
import javafx.scene.layout.VBox;

import java.io.File;
import java.net.URISyntaxException;
import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;

public class Controller implements Initializable {
    File actualFile;

    FileSelector fileSelector;

    @FXML
    ComboBox<String> pathSelector;

    @FXML
    TreeView<File> fileTreeView;

    void initializeFileView() {
        fileTreeView.
        TreeItem<File> treeRoot = new TreeItem<>();
        for (File root : File.listRoots()) {
            TreeItem<File> rootItem = new TreeItem<>(root);
            if (root.isDirectory())
                for (File rootChild : root.listFiles()) {
                    TreeItem<File> rootChildItem = new TreeItem<>(rootChild);
                    rootChildItem.setGraphic(new Label(rootChild.getName()));
                    rootItem.getChildren().add(rootChildItem);
                }
            rootItem.setGraphic(new Label(root.getName()));
            rootItem.
            treeRoot.getChildren().add(rootItem);
        }
        fileTreeView.setRoot(treeRoot);
        fileTreeView.setShowRoot(false);
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        initializeFileView();
        try {
            actualFile = new File(location.toURI());
        } catch (URISyntaxException e) {
            actualFile = File.listRoots()[0];
            System.out.println(e.getMessage());
        }
        fileSelector = new FileSelector();
        /**/
        pathSelector.setPromptText(actualFile.getName());
        /**/
        TreeItem<File> root = new TreeItem<>();
        FileSelector.listParents("");
    }
}
