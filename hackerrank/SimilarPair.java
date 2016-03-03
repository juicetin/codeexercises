import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class SimilarPair {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            // Read number of nodes
            String input = br.readLine();
            String[] parts = input.split(" ");
            int nodes = Integer.parseInt(parts[0]);
            int k = Integer.parseInt(parts[1]);

            // New unordered binary tree
            BinaryTree tree = new BinaryTree();

            // Read all ancestor/child pairs
            for (int i = 0; i < nodes - 1; ++i) {
                input = br.readLine();
                String[] nums = input.split(" ");
                int ancestor = Integer.parseInt(nums[0]);
                int child = Integer.parseInt(nums[1]);

                tree.insert(ancestor, child);
            }

            // Get result!
            int similarPairs = tree.getSimilarPairs(k);
            System.out.println(similarPairs);
            // tree.printTreeInOrder();

        } catch (IOException error) { }
    }
}

class BinaryTree {
    public BinaryTree() {
        this.root = null;
    }

    public Node getRoot() {
        return this.root;
    }

    /*
     *  Comparisons
     */
    public int getSimilarPairs(int k) {
        this.similarPairs = 0;
        this.difference = k;
        traverseAllNodes(this.root);

        return this.similarPairs;
    }

    public void traverseAllNodes(Node relRoot) {
        if (relRoot != null) {
            compareWithAllChildren(relRoot, relRoot);
            for (Node childNode : relRoot.children) {
                traverseAllNodes(childNode);
            }
        }
    }

    public void compareWithAllChildren(Node relRoot, Node nextRelRoot) {
        for(Node childNode : nextRelRoot.children) {
            compareTwoNodesSimilarity(relRoot, childNode);
            compareWithAllChildren(relRoot, childNode);
        }
    }

    public void compareTwoNodesSimilarity(Node first, Node second) {
        // First check if both nodes are valid
        boolean bothNodesExist = first != null && second != null;
        if (!bothNodesExist) {
            return;
        }

        if (Math.abs(first.getValue() - second.getValue()) <= this.difference) {
            this.similarPairs++;
        }
    }

    /*
     *  Printing
     */
    public void printTreeInOrder() {
        printInOrderRecursive(this.root);
        System.out.println();
    }
    public void printInOrderRecursive(Node relRoot) {
        if (relRoot != null) {
            System.out.print(relRoot.getValue());
            for (Node childNode : relRoot.children) {
                printInOrderRecursive(childNode);
            }
        }
    }

    /*
     *  Inserting
     */
    public void insert(int ancestor, int child) {
        // Create both nodes if none exist yet
        if (this.root == null) {
            this.root = new Node(ancestor);

            this.root.children.add(new Node(child));
            // this.root.left = new Node(child);
            return;
        }
        recursiveInsert(root, ancestor, child);
    }
    public void recursiveInsert(Node relativeRoot, int ancestor, int child) {
        // Once we've reached the ancestor node
        if (relativeRoot != null && relativeRoot.getValue() == ancestor) {
            // Insert new child
            relativeRoot.children.add(new Node(child));
            return;
        } 

        // Recurse into (no!-each side-) all children to find the appropriate ancestor
        for (Node childNode : relativeRoot.children) {
            recursiveInsert(childNode, ancestor, child);
        }
    }

    private Node root;
    private int similarPairs;
    private int difference;
}

class Node {
    public Node(int value) {
        this.value = value;
        this.left = null;
        this.right = null;
        this.children = new ArrayList<Node>();
    }

    public int getValue() {
        return this.value;
    }

    private int value;
    public Node left;
    public Node right;

    public ArrayList<Node> children;
}
