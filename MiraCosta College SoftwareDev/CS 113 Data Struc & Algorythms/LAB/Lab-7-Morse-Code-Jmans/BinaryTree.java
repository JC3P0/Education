import java.io.Serializable;
import java.util.Scanner;

/**
 * BinaryTree.java:
 *
 * @param <E> data type of the tree.
 **
 * @author
 * @version 1.0
 */
public class BinaryTree<E>  {

    //data field
    protected Node<E> root;


    /**
     * Default constructor
     */
    public BinaryTree(){
        this.root = null;
    }

    /**
     * Constructor, assigns the node to the root of the tree.
     *
     * @param root node being assigned to the root.
     */
    public BinaryTree(Node<E> root){
        this.root = root;
    }

    /**
     * Tree constructor, builds a tree by adding two existing trees root node to the
     * left and right nodes of a new root node. The root node is created from the data passed
     * to method.
     *
     * @param data to be assigned to the root node.
     * @param leftTree tree being added to left side of the tree.
     * @param rightTree tree being added to the right side of the tree.
     */

    public BinaryTree(E data, BinaryTree<E> leftTree, BinaryTree<E> rightTree){
        this.root = new Node<E>(data);
        //there
        if(leftTree == null){
            this.root.left = null;
        } else {
            this.root.left =  leftTree.root;
        }

        if(rightTree == null){
            this.root.right = null;
        } else {
            this.root.right =  rightTree.root;
        }
    }
    /**
     * Returns the subtree to the left of the root. Returns null if the tree is empty
     * or there is no left subtree.
     *
     * @return the left subtree of the root node.
     */
    public BinaryTree<E> getLeftSubtree(){
        if(root != null && root.left != null){
            return new BinaryTree<>(root.left);
        }
        return null;
    }

    /**
     * Returns the subtree to the right of the root. Returns null if the tree is empty
     * or there is no right subtree.
     *
     * @return the right subtree if the root node.
     */
    public BinaryTree<E> getRightSubtree(){
        if(root != null && root.right != null){
            return new BinaryTree<>(root.right);
        }
        return null;
    }


    /**
     * Checks to see if the current node is a leaf.
     *
     * @return boolean if the node is a leaf.
     */
    public boolean isLeaf(){
        return (root.left == null && root.left == null);
    }


    /**
     * Returns the roots node data value.
     *
     * @return data of root node.
     */
    public E getData(){
        return root.data;
    }


    /**
     * Returns a representation of the tree where each subtree is indented by the number of its depth.
     * Calls preOrderTraverse to recursively traverse the tree.
     *
     * @return String representation of the tree.
     */
    public String toString(){


        StringBuilder sb = new StringBuilder();
        preOrderTraverse(root, 1, sb);
        return sb.toString();
    }

    /**
     * Recursively traverse the tree and adds to the string.
     *
     * @param node current node in the tree.
     * @param depth depth of the node in the tree.
     * @param sb String representation of the tree.
     */
    
    private void preOrderTraverse(Node<E> node, int depth, StringBuilder sb){
        for (int i = 1; i < depth; i++){
            sb.append(" ");
        }
        if(node == null){
            sb.append("null\n");
        } else {
            sb.append(node.toString() + "\n");
            preOrderTraverse(node.left, depth + 1, sb);
            preOrderTraverse(node.right, depth + 1, sb);
        }
    }

    /**
     * Reconstructs the tree created by the toString method. Returns a new binary tree
     * constructed by the tree constructor.
     *
     * @param scan scanner used to read a file.
     * @return BinaryTree constructed from the read file.
     */
    public static BinaryTree<String> readBinaryTree(Scanner scan){
        String data = scan.next();
        if(data.equals("null")){
            return null;
        } else {
            BinaryTree<String> leftTree = readBinaryTree(scan);
            BinaryTree<String> rightTree = readBinaryTree(scan);
            return new BinaryTree<String>(data, leftTree, rightTree);
        }
    }





    /**
     * Tree node represents data in a binary tree.
     * @param <E> data type of the binary tree.
     */
   protected static class Node<E>  {
       //data fields
       protected E data;
       protected Node<E> left;
       protected Node<E> right;

       //constructor
       public Node(E data){
           this.data = data;
           this.left = null;
           this.right = null;
       }

       @Override
       public String toString(){
           return this.data.toString();
       }
   }
}