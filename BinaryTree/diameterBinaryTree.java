package BinaryTree;

public class diameterBinaryTree {

  int mx;

  public int func(TreeNode node) {

    if (node == null) {
      return 0;
    }

    int l = func(node.left);
    int r = func(node.right);

    mx = Math.max(mx, l + r + 1);

    return Math.max(r, l) + 1;

  }

  public int height(TreeNode root) {
    mx = Integer.MIN_VALUE;
    int x = func(root);
    return mx;
  }

}
