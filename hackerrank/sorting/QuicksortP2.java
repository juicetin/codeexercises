import java.util.*;

public class QuicksortP2 {

    /*
     *  Merge smaller, equal, and larger arrays into a single prim array
     */
    static int[] merge(int[] smaller, int[] equal, int[] larger) {
        int size = smaller.length + equal.length + larger.length;
        int[] ar = new int[size];
        for (int i = 0; i < smaller.length; ++i) {
            ar[i] = smaller[i];
        }

        for (int i = 0; i < equal.length; ++i) {
            ar[smaller.length + i] = equal[i];
        }

        for (int i = 0; i < larger.length; ++i) {
            ar[smaller.length + equal.length + i] = larger[i];
        }

        printArray(ar);
        return ar;
    }

    /*
     *  Partition an array into smaller, equal, larger segments
     *  Recursively partition and merge as appropriate
     */
    static int[] partition(int[] ar) {
        if (ar.length <= 1) {
            return ar;
        }

        int pivot = ar[0];

        ArrayList<Integer> smaller = new ArrayList<Integer>();
        ArrayList<Integer> larger = new ArrayList<Integer>();
        ArrayList<Integer> equal = new ArrayList<Integer>();

        // Partition into left, equal, right
        for (int i = 0; i < ar.length; ++i) {
            if (ar[i] < pivot) {
                smaller.add(ar[i]);
            } else if (ar[i] > pivot) {
                larger.add(ar[i]);
            } else {
                equal.add(ar[i]);
            }
        }
        
        int[] smallerAr = arrayListToPrimArray(smaller);
        int[] equalAr = arrayListToPrimArray(equal);
        int[] largerAr = arrayListToPrimArray(larger);

        // return merge(smallerAr, equalAr, largerAr);
        int[] sortedSmaller = partition(smallerAr);
        int[] sortedLarger = partition(largerAr);
        return merge(sortedSmaller, equalAr, sortedLarger);
    }

    static int[] arrayListToPrimArray(ArrayList<Integer> arrList) {
        int[] ar = new int[arrList.size()];
        for (int i = 0; i < arrList.size(); ++i) {
            ar[i] = arrList.get(i);
        }
        return ar;
    }

    static void quickSort(int[] ar) {
        ar = partition(ar);
        // printArray(ar);
    }   

    static void printArray(int[] ar) {
        for(int n: ar){
            System.out.print(n+" ");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] ar = new int[n];
        for(int i=0;i<n;i++){
            ar[i]=in.nextInt(); 
        }
        quickSort(ar);
    }    
}

