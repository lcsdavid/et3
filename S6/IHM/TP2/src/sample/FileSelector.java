package sample;

import tree.Tree;
import tree.Node;

import java.io.File;
import java.util.ArrayList;
import java.util.Objects;

public class FileSelector {
    private File cursor = null;
    private Tree<File> fileTree = new Tree<>();

    public FileSelector() {
        File[] listRoots = File.listRoots();
        fileTree.setRoot(new Node<>());
        for(File file: File.listRoots()) {
            Node<File> node = new Node<>(file);
            if(file.isDirectory()) {
                File[] listFiles = file.listFiles();
                if(listFiles != null)
                    for (File subFile: listFiles)
                        node.addChild(new Node<>(subFile));
            }
            fileTree.getRoot().addChild(node);
        }
    }

    public FileSelector(String path) {
        this();
        cursor = new File(path);
        if (cursor.exists()) {

            File parent = cursor.getParentFile();
            System.out.println();





        }
    }


/*
    public Node<File> search(File file) {

    }

    public static File[] listParents(String path) {
        File file = new File(path);
        System.out.println(file.getParent());
        if(!file.exists())
            return null;
        File[] files = new File[5];
        System.out.println(file.getParent());
        String absolutePath = file.getAbsolutePath();
        while (!absolutePath.isEmpty()) {

        }
        return null;
    }

    // Retourne une Arraylist des parents du fichier Path
    /*public ArrayList<String> getListRepParent(String path) {
        String actualPath = "";
        File dir = new File(path);
        if (!dir.exists() || !dir.isDirectory())
            return null;

        directory = dir.getAbsolutePath();
        System.out.println(directory) ;
        file = null;

        String[] files = dir.list();
        if (files != null) {
            for (int i = 0; i < files.length; i++) {
                File f = new File(path, files[i]);
                if (f.isDirectory()) files[i] = files[i] + File.separator;
                System.out.format("  file: %s\n",files[i]) ;
            }
        }

        System.out.format("  parentdir: %s\n",File.separator) ;
        listRepParent.clear();
        String[] dirs = path.split(File.separator);
        for (String p : dirs) {
            actualPath += p + File.separator;
            if (p.equals("")) continue ;
            listRepParent.add(actualPath);
            System.out.format("  parentdir: %s\n",p) ;
        }
        return listRepParent;
    }

    //retourne une arraylist des fichier present dans le dossier Path
    public ArrayList<String> getListFile(String path) {
        File dir = new File(path);

        if (!dir.exists() || !dir.isDirectory()) return null;

        directory = dir.getAbsolutePath();
        file = null;

        String[] files = dir.list();
        if (files != null) {
            listFile.clear();
            for (int i = 0; i < files.length; i++) {
                File f = new File(path, files[i]);
                if (f.isDirectory()) {
                    files[i] = files[i] + File.separator;
                    listFile.add(f.getName() + File.separator);
                } else if (f.isFile()) {
                    listFile.add(f.getName());
                }
                // System.out.format("  file: %s\n",files[i]) ;
            }
        }
        return listFile;
    }

*/
}