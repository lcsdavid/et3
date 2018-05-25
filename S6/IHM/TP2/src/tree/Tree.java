package tree;

public class Tree<T> {
    private Node<T> root = null;

    public Tree() {
        super();
    }

    public Tree(Node<T> root) {
        this.root = root;
    }

    public void setRoot(Node<T> root) {
        this.root = root;
    }

    public Node<T> getRoot() {
        return root;
    }


}
