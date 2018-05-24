import java.util.LinkedList;
import java.util.List;

public class TreeNode<T> extends LinkedList {
    T data;
    TreeNode<T> parent;
    List<TreeNode<T>> childrens;

    public TreeNode() {
        super();
    }

    public TreeNode(T data) {
        this.data = data;
    }

    public

}
