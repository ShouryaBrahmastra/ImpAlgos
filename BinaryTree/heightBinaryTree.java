package BinaryTree;

public class heightBinaryTree {

  public int height(TreeNode root) {

    if (root == null) {
      return -1;
    }

    int left = height(root.left);
    int right = height(root.right);

    return Math.max(left, right) + 1;
  }

}
