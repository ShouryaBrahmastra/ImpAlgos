package BinaryTree;

import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Stack;

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

  public void preOrderRec(ArrayList<Integer> arr, TreeNode node) {

    if (node == null) {
      return;
    }

    arr.add(node.data);
    preOrderRec(arr, node.left);
    preOrderRec(arr, node.left);

  }

  public void inOrderRec(ArrayList<Integer> arr, TreeNode node) {

    if (node == null) {
      return;
    }

    inOrderRec(arr, node.left);
    arr.add(node.data);
    inOrderRec(arr, node.left);

  }

  public void postOrderRec(ArrayList<Integer> arr, TreeNode node) {

    if (node == null) {
      return;
    }

    postOrderRec(arr, node.left);
    postOrderRec(arr, node.left);
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

  public ArrayList<Integer> preOrderItr(TreeNode root) {

    Stack<TreeNode> st = new Stack<>();
    ArrayList<Integer> arr = new ArrayList<>();

    st.push(root);

    TreeNode curr = root;

    while (!st.isEmpty()) {
      if (curr != null) {
        arr.add(curr.data);
        if (curr.right != null) {
          st.push(curr.right);
        }
        curr = curr.left;
      } else {
        curr = st.pop();
      }

    }
    return arr;
  }

  public ArrayList<Integer> inOrderItr(TreeNode root) {

    Stack<TreeNode> st = new Stack<>();
    ArrayList<Integer> arr = new ArrayList<>();

    TreeNode curr = root;

    while (!st.isEmpty() || curr != null) {

      if (curr != null) {
        st.push(curr);
        curr = curr.left;
      } else {
        curr = st.pop();
        arr.add(curr.data);
      }

      curr = curr.right;

    }
    return arr;
  }

  public ArrayList<Integer> postOrderItr(TreeNode root) {

    if (root == null) {
      return null;
    }

    Stack<TreeNode> st = new Stack<>();
    ArrayList<Integer> arr = new ArrayList<>();

    Stack<Integer> out = new Stack<>();

    while (!st.isEmpty()) {
      TreeNode curr = st.pop();
      out.push(curr.data);

      if (curr.left != null) {
        st.push(curr.left);
      }

      if (curr.right != null) {
        st.push(curr.right);
      }
    }

    while (!out.isEmpty()) {
      arr.add(out.pop());
    }

    return arr;
  }

}