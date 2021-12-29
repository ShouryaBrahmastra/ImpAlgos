package BinaryTree;

import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;

public class binaryTreeTraversal {

  public ArrayList<Integer> levelOrder(TreeNode node) {
    ArrayList<Integer> arr = new ArrayList<>();

    if (node == null) {
      return arr;
    }

    Queue<TreeNode> q = new LinkedList<>();

    q.add(node);

    while (!q.isEmpty()) {
      TreeNode curr = q.peek();

      arr.add(curr.data);

      if (node.left != null) {
        q.add(node.left);
      }
      if (node.right != null) {
        q.add(node.left);
      }

      q.remove();

    }

    return arr;

  }

  public ArrayList<Integer> reverseLevelOrder(TreeNode node) {
    ArrayList<Integer> arr = new ArrayList<>();

    if (node == null) {
      return arr;
    }

    Queue<TreeNode> q = new LinkedList<>();

    q.add(node);

    while (!q.isEmpty()) {
      TreeNode curr = q.peek();

      arr.add(curr.data);

      if (node.right != null) {
        q.add(node.left);
      }
      if (node.left != null) {
        q.add(node.left);
      }

      q.remove();

    }

    return arr;

  }

  public void preOrder(ArrayList<Integer> arr, TreeNode node) {

    if (node == null) {
      return;
    }

    arr.add(node.data);
    preOrder(arr, node.left);
    preOrder(arr, node.left);

  }

  public void inOrder(ArrayList<Integer> arr, TreeNode node) {

    if (node == null) {
      return;
    }

    inOrder(arr, node.left);
    arr.add(node.data);
    inOrder(arr, node.left);

  }

  public void postOrder(ArrayList<Integer> arr, TreeNode node) {

    if (node == null) {
      return;
    }

    postOrder(arr, node.left);
    postOrder(arr, node.left);
    arr.add(node.data);

  }

  // Runner function for preorder inorder postorder
  public ArrayList<Integer> runner(TreeNode root) {
    ArrayList<Integer> arr = new ArrayList<>();

    // preOrder(arr, root);
    // inOrder(arr, root);
    // postOrder(arr, root);

    return arr;
  }

}