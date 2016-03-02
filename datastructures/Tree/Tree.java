import java.io.*;
import java.util.*;

class Node {
    public Node() {
    }
    public Node(int data) {
        this.data = data;
    }
    int data;
    Node left;
    Node right;
}

class Tree {
    public static void Preorder(Node root) {
        if (root != null) {
            System.out.print(root.data + " ");
        }

        if (root.left != null) {
            Preorder(root.left);
        }

        if (root.right != null) {
            Preorder(root.right);
        }

    }

    public static void Postorder(Node root) {
        if (root.left != null) {
            Postorder(root.left);
        }

        if (root.right != null) {
            Postorder(root.right);
        }

        System.out.print(root.data + " ");
    }

    public static void Inorder(Node root) {
        if (root.left != null) {
            Inorder(root.left);
        }

        if (root != null) {
            System.out.print(root.data + " ");
        }

        if (root.right != null) {
            Inorder(root.right);
        }
    }

    int height(Node root) {
        if (root == null) {
            return 0;
        }

        int leftHeight = height(root.left);
        int rightHeight = height(root.right);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }

    void left_view(Node root) {
        if(root != null) {
            left_view(root.left);
            System.out.print(root.data + " ");
        }
    }

    void right_view(Node root) {
        if(root != null) {
            System.out.print(root.data + " ");
            right_view(root.right);
        }  
    }

    void top_view(Node root)
    {
        left_view(root.left);
        if (root != null) {
            System.out.print(root.data + " ");
        }
        right_view(root.right);
    }

    void LevelOrder(Node root) {
        Queue<Node> BFSqueue = new LinkedList<Node>();
        if (root == null) {
            return;
        }
        BFSqueue.add(root);

        // Empty out queue (no cycles in a binary tree)
        while(!BFSqueue.isEmpty()) {
            // Pop off front element
            Node popped = (Node) BFSqueue.remove();
            System.out.print(popped.data + " ");

            // Append left child
            if (popped.left != null) {
                BFSqueue.add(popped.left);
            }

            // Append right child
            if (popped.right != null) {
                BFSqueue.add(popped.right);
            }
        }
    }

    static Node Insert(Node root, int value) {
        if (root == null) {
            root = new Node();
            root.data = value;
        } else {
            if (root.data <= value) {
                root.left = Insert(root.left, value);
            } else {
                root.right = Insert(root.right, value);
            }
        }
        return root;
    }

    public static void swapToIncreasing(int a, int b) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
    }

    public static boolean nodeDataBetweenTwo(Node node, int a, int b) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        return node.data > a && node.data < b;
    }

    public static boolean nodeDataGreaterThanTwo(Node node, int a, int b) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        return node.data > a && node.data > b;
    }

    public static boolean nodeDataLessThanTwo(Node node, int a, int b) {
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        return node.data < a && node.data < b;
    }

    public static Node lca(Node root, int v1, int v2) {
        Node lcaNode = null;
        if (nodeDataBetweenTwo(root, v1, v2)) {
            lcaNode = root;
        } else if (nodeDataLessThanTwo(root, v1, v2)) {
            lcaNode = lca(root.right, v1, v2);
        } else if (nodeDataGreaterThanTwo(root, v1, v2)) {
            lcaNode = lca(root.left, v1, v2);
        }

        if (lcaNode == null) {
            lcaNode = root;
        }
        return lcaNode;
    }

    public static void main(String args[]) {
        System.out.println("hi");

        Node one = new Node(1);
        Node two = new Node(2);
        Node three = new Node(3);
        Node four = new Node(4);
        Node five = new Node(5);
        Node six = new Node(6);
        Node eight = new Node(8);
        Node nine = new Node(9);
        Node eleven = new Node(11);
        Node twelve = new Node(12);
        Node sixteen = new Node(16);

        nine.left = four;
        nine.right = twelve;
        four.left = two;
        four.right = six;
        two.left = one;
        two.right = three;
        six.left = five;
        six.right = eight;
        twelve.left = eleven;
        twelve.right = sixteen;

        Node thisOne = lca(nine, 11, 1);
        System.out.println(thisOne.data);
    }
}

