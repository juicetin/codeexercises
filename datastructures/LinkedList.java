class LinkedList {

    int FindLLLength(Node headA) {
        int length = 0;
        while (headA != null) {
            length++;
            headA = headA.next;
        }
        return length-1;
    }

    int FindMergeNode(Node headA, Node headB) {
        int lengthA = FindLLLength(headA);
        int lengthB = FindLLLength(headB);

        Node headLonger;
        Node headShorter;
        int lengthDiff;
        if (lengthA > lengthB) {
            headLonger = headA;
            headShorter = headB;
            lengthDiff = lengthA - lengthB;
        } else {
            headLonger = headB;
            headShorter = headA;
            lengthDiff = lengthB - lengthA;
        }

        while (lengthDiff-- >= 0) {
            headLonger = headLonger.next;
        }

        return headLonger.next.data;
    }

    int HasCycle(Node head) {

        Node curHead = head;
        Node curRunnerHead = head;
        while (curHead != null && curRunnerHead.next != null) {
            curHead = curHead.next;
            curRunnerHead = curRunnerHead.next.next;
            if (curHead == null || curRunnerHead == null) return 0;
            if (curHead == curRunnerHead) {
                return 1;
            }
        }

        return 0;
    }

    Node RemoveDuplicates(Node head) {
        Node curHead = head;
        while (curHead != null && curHead.next != null) {
            if (curHead.data == curHead.next.data) {
                // would otherwise delete the node at curHead.next here
                curHead.next = curHead.next.next;
            } else {
                curHead = curHead.next;
            }
        }

        return head;
    }

    int GetNode(Node head, int n) {
        Node runAhead = head;
        while(n >= 0) {
            runAhead = runAhead.next;
            n--;
        }

        Node wantedNode = head;
        while (runAhead != null) {
            runAhead = runAhead.next;
            wantedNode = wantedNode.next;
        }

        return wantedNode.data;
    }

    public static void MergeListsRecursive(Node headA, Node headB, Node curMergedHead) {
        if (headA == null) {
            curMergedHead.next = headB;
            return;
        } else if (headB == null) {
            curMergedHead.next = headA;
            return;
        }

        if (headA.data < headB.data) {
            curMergedHead.next = headA;
            headA = headA.next;
        } else {
            curMergedHead.next = headB;
            headB = headB.next;
        }
        curMergedHead = curMergedHead.next;
        MergeListsRecursive(headA, headB, curMergedHead);
    }

    public static Node MergeListsRecursiveSetup(Node headA, Node headB) {
        Node mergedHead = new Node();
        Node curMergedHead = mergedHead;

        MergeListsRecursive(headA, headB, curMergedHead);
        return mergedHead.next;
    }

    public static Node MergeLists(Node headA, Node headB) {
        // If any one list is empty, the rest can be attached on
        if (headA == null) {
            return headB;
        } else if (headB == null) {
            return headA;
        }

        // Merged head starts at list with smaller data
        Node mergedHead = new Node();

        Node mergedCur = mergedHead;
        // While both lists still have elements left
        while (headA != null && headB != null) {
            // Move headA/B forward depending on which one was smaller
            if (headA.data < headB.data) {
                mergedCur.next = headA;
                headA = headA.next;
            } else {
                mergedCur.next = headB;
                headB = headB.next;
            }

            // Move merged list pointer to the newly assigned smaller node
            mergedCur = mergedCur.next;
        }

        // Attach the non-null list to the end of the merged list
        if (headA != null) {
            mergedCur.next = headA;
        } else if (headB != null) {
            mergedCur.next = headB;
        }

        return mergedHead.next;
    }


    boolean NullHeadsEqual(Node headA, Node headB) {
        if ((headA == null && headB != null) || (headB == null && headA != null) ) {
            return false;
        }
        return true;
    }

    int CompareLists(Node headA, Node headB) {
        // This is a "method-only" submission. 
        // You only need to complete this method 

        if (!NullHeadsEqual(headA, headB)) {
            return 0;
        }

        while (headA != null || headB != null) {
            if (!NullHeadsEqual(headA, headB) || headA.data != headB.data) {
                return 0;
            }
            headA = headA.next;
            headB = headB.next;
        }
        return 1;
    }

    int CompareListsRecursive(Node headA, Node headB) {
        if (headA == headB) {
            return 1;
        } else if (!NullHeadsEqual(headA, headB) || headA.data != headB.data) {
            return 0;
        }

        return CompareListsRecursive(headA.next, headB.next);
    }

    public static Node Reverse(Node head) {
        return new Node();
    }

    public static void ReversePrint(Node head) {
        if (head != null ) {
            if (head.next != null) {
                ReversePrint(head.next);
            }
            System.out.println(head.data);
        }
    }

    public static Node Delete(Node head, int position) {
        if (position == 0) {
            return head.next;
        }

        Node insertPosPrev = FindNth(head, position-1);
        insertPosPrev.next = insertPosPrev.next.next;
        return head;
    }

    public static Node FindNth(Node head, int position) {
        Node insertPos = head;
        for (int i = position; i > 0; i--) {
            insertPos = insertPos.next;
        }
        return insertPos;
    }

    public static Node InsertNth(Node head, int data, int position) {
        // This is a "method-only" submission. 
        // You only need to complete this method. 

        // Initialise head if needed
        if (head == null) {
            head = new Node();
        }

        // Move 'iterator' over to one before point of insertion
        Node insertPosPrev = FindNth(head, position-1);

        // New node goes after this position - 
        //  make this one's next the new one,
        //  and the one after it this one's next's next
        Node newNode = new Node();
        newNode.data= data;

        // Position 0 means there's a new head
        if (position == 0) {
            newNode.next = head;
            return newNode;
        }

        // Adjust node next pointers
        newNode.next = insertPosPrev.next;
        insertPosPrev.next = newNode;
        return head;

    }

    public static Node Insert(Node head,int data) {
        // This is a "method-only" submission. 
        // You only need to complete this method. 

        // If head is null, create new node and assign data
        if (head == null) {
            head = new Node();
            head.data = data;
            head.next = null;
            return head;
        }

        // Otherwise, iterate to the tail and assign a new, next node
        Node tail = head;
        while(tail.next != null) {
            tail = tail.next;
        }
        tail.next = new Node();
        tail.next.data = data;

        return head;
    }


    public static Node reverseLinkedList(Node head) {
        Node prevNode = null;
        Node nextNode;
        while (head != null) {
            nextNode = head.next;

            // reverse the link
            head.next = prevNode;

            // move current and prevNode by 1 node
            prevNode = head;
            head = nextNode;
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

        Node head = new Node(0);
        Node curHead = head;
        for (int i = 1; i < SIZE; ++i) {
            Node nextNode = new Node(i);
            curHead.next = nextNode;
            curHead = nextNode;
        }
        curHead = head;
        // curHead = InsertNth(curHead, 7, 4);
        // curHead = Insert(curHead, 5);
        ReversePrint(curHead);

        // curHead = reverseLinkedListRecursive(curHead);
        // while (curHead != null) {
        //     System.out.println(curHead.getValue());
        //     curHead = curHead.next;
        // }
    }
}

class Node {
    public Node(int data) {
        this.data = data;
        this.next = null;
    }

    public Node() {
        this.next = null;
    }

    public Node next;

    public int getValue() {
        return this.data;
    }

    public int data;
}

