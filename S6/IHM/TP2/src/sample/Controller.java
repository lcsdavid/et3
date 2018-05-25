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


    private File actualFile;


    @FXML
    private TextField pathSelector;

    @FXML
    private TreeView<String> fileView;

    private void initializeFileView() {
        fileView.setRoot(new TreeItem<>(""));
        for (File root : File.listRoots()) {
            insert(root.getPath());
            insertChildren(root);
        }
        fileView.setShowRoot(false);
    }



    private void setGraphic(TreeItem<String> item) {
        String path = item.getValue();
        TreeItem<String> it = item.getParent();
        while (it != null) {
            path = it.getValue() + '\\' + path;
            it = it.getParent();
        }
        ImageView imageView = new ImageView("file:" + new File("rsc/dirIcon.png").getAbsolutePath());
        imageView.setFitWidth(16);
        imageView.setPreserveRatio(true);
        item.setGraphic(imageView);
       /* File file = new File(path);
        if (file.isDirectory())
            item.setGraphic(dirIcon);
        else if (file.isFile())
            item.setGraphic(fileIcon);
        else if (file.isHidden())
            item.setGraphic(hiddenDirIcon);*/
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
        actualFile = new File("");
        pathSelector.setText(actualFile.getAbsolutePath());
        /**/

        /* fill tree */
        initializeFileView();
        TreeItem<String> current = insert(actualFile.getAbsolutePath());
        expand(current);
        select(current);
        /**/

    }

    private TreeItem<String> insert(String path) {
        String[] splitedPath = path.split("\\\\");
        String currentPath = splitedPath[0];
        TreeItem<String> currentItem = fileView.getRoot();
        for (String split: splitedPath) {
            ObservableList<TreeItem<String>> copy = FXCollections.observableArrayList(currentItem.getChildren());
            copy.removeIf(item -> !item.getValue().equals(split));
            if(copy.isEmpty()) {
                TreeItem<String> child = new TreeItem<>(split);
                currentItem.getChildren().add(child);
                setGraphic(child);
                currentItem = child;
            } else {
                currentItem = copy.get(0);
            }
            currentPath += '\\' + split;

        }
        return currentItem;
    }

    private void insertChildren(File parent) {
        if(parent.isDirectory()) {
            File[] children = parent.listFiles();
            if(children != null)
                for(File file: children)
                    insert(file.getPath());
        }
    }

    private void insertChildren(TreeItem<String> item) {
        String path = item.getValue();
        TreeItem<String> currentItem = item;
        while (currentItem != null) {
            path = item.getValue() + '\\' + path;
            currentItem = currentItem.getParent();
        }
        File parent = new File(path);
        insertChildren(parent);
    }

    private void expand(TreeItem<String> item) {
        insertChildren(item);
        while (item != null) {
            item.setExpanded(true);
            item = item.getParent();
        }
    }

    private void select(TreeItem<String> item) {
        int index = fileView.getRow(item);
        fileView.getSelectionModel().select(index);
        fileView.scrollTo(index);
    }


}
