
public class Tree<T> {
    private TreeNode<T> root;

    public Tree() {
        root = null;
    }

    public Tree(T root) {
        root = new TreeNode<>(root);
    }
}
