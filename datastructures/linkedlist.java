class LinkedList {

    public static Node reverseLinkedList(Node curHead) {
        Node prevNode = null;
        Node nextNode;
        while (curHead != null) {
            nextNode = curHead.next;

            // reverse the link
            curHead.next = prevNode;

            // move current and prevNode by 1 node
            prevNode = curHead;
            curHead = nextNode;
        }

        return prevNode;
    }

    public static Node reverseLinkedListRecursive(Node curHead) {
        if (curHead == null || curHead.next == null) {
            return curHead;
        }

        Node remaining = reverseLinkedListRecursive(curHead.next);
        curHead.next.next = curHead;
        curHead.next = null;

        return remaining;
    }

    static int SIZE = 10;

    public static void main (String[] args) {
        System.out.println("hi there");

        Node head = new Node(0);
        Node curHead = head;
        for (int i = 1; i < SIZE; ++i) {
            Node nextNode = new Node(i);
            curHead.next = nextNode;
            curHead = nextNode;
        }
        curHead = head;

        curHead = reverseLinkedListRecursive(curHead);
        while (curHead != null) {
            System.out.println(curHead.getValue());
            curHead = curHead.next;
        }
    }
}

class Node {
    public Node(int value) {
        this.value = value;
        this.next = null;
    }

    public Node next;

    public int getValue() {
        return this.value;
    }

    private int value;
}

