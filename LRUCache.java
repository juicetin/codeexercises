import java.util.*;

class Buffer {
    public char page;
    public boolean visitedBit;
    public int location;

    public Buffer(char page, boolean visitedBit, int location) {
        this.page = page;
        this.visitedBit = visitedBit;
        this.location = location;
    }
}

class Clock {
    int size;
    Buffer[] clock;
    int curPointer;
    HashMap<Character, Integer> pagesInBuffer; // page name and location in buffer

    public Clock(int size) {
        this.size = size;
        this.curPointer = 0;
        this.clock = new Buffer[size];
        this.pagesInBuffer = new HashMap<Character, Integer>();
    }

    public void insertPage(char page) {

        // Page we want to 'insert' already exists in our buffer,
        // don't insert it, but mark its visited 'bit' to true
        if (this.pagesInBuffer.containsKey(page)) {
            int positionOfPage = this.pagesInBuffer.get(page);
            this.clock[positionOfPage].visitedBit = true;
        } 

        // Buffer at pointer is still empty
        else if (this.clock[this.curPointer] == null) {

            // Insert page into the empty buffer
            this.clock[this.curPointer] = new Buffer(page, false, this.curPointer);

            // Mark page as being in our set
            this.pagesInBuffer.put(this.clock[this.curPointer].page, 
                    this.clock[this.curPointer].location);

            // Move pointer to next buffer
            this.incrementPointer();
        } 


        // Otherwise, we need to rotate around the clock to find 
        // the next available bit - and keep doing so until we find
        // a buffer with its visited bit off
        else {
            while(this.clock[this.curPointer].visitedBit) {
                this.clock[this.curPointer].visitedBit = false;
                this.incrementPointer();
            }

            // Remove page to be removed from the set of pages in buffer
            this.pagesInBuffer.remove(this.clock[this.curPointer].page);

            // We are now at a buffer with its visited bit off!
            // So, we can insert our new page.
            this.clock[this.curPointer] = new Buffer(page, false, this.curPointer);

            // Mark our new page as in the buffer
            this.pagesInBuffer.put(this.clock[this.curPointer].page, 
                    this.clock[this.curPointer].location);

            // Move pointer to next buffer
            this.incrementPointer();
        }
    }

    /*
     *  Increments pointer in a cyclical fashion using a normal array
     */
    private void incrementPointer() {
        // If we won't hit the end, increment pointer
        if (this.curPointer < this.clock.length - 1) {
            this.curPointer++;
        } else {
            // Otherwise, reset back to the beginning
            this.curPointer = 0;
        }
    }

    public void printPages() {
        for (Buffer buffer : this.clock) {
            if (buffer != null) {
                System.out.print(buffer.page + " ");
            }
        }
        System.out.println();
    }
}


public class LRUCache {
    public static void insertPages(char[] pages) {
        Clock clock = new Clock(3);
        for (char page : pages) {
            clock.insertPage(page);
        }

        clock.printPages();
    }

    public static void main(String args[]) {
        char[] pages = new char[] {'a', 'b', 'd', 'c', 'b', 'b', 'e', 'a'};
        insertPages(pages);

        // Expected result for above sample - a, b, e at the end
    }
}
