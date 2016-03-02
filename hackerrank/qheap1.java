import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class qheap1 {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String input;
            int ops = Integer.parseInt(br.readLine());

            for (int i = 0; i < ops; ++i) {
                input = br.readLine();
                int operation = Integer.parseInt(input.split(" ")[0]);
            }

        } catch(IOException error) { }
    }
}

class Node {
    int data;
    Node left;
    Node right;
}

class Heap {
    public Heap () {
    }

    public void upHeap() {
    }

    public void downHeap() {
    }

    public int getMin() {
        return root.data;
    }

    Node root;
    Node lastInserted;
}
