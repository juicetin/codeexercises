import java.util.*;
public class QuicksortP1 {

    static void partition(int[] ar) {
        int pivot = ar[0];
        ArrayList<Integer> smaller = new ArrayList<Integer>();
        ArrayList<Integer> larger = new ArrayList<Integer>();
        ArrayList<Integer> equal = new ArrayList<Integer>();

        for (int i = 0; i < ar.length; ++i) {
            if (ar[i] < pivot) {
                smaller.add(ar[i]);
            } else if (ar[i] > pivot) {
                larger.add(ar[i]);
            } else {
                equal.add(ar[i]);
            }
        }

        printArrayList(smaller);
        printArrayList(equal);
        printArrayList(larger);
    }

    static void printArrayList(ArrayList<Integer> arrList) {
        for (int element : arrList) {
            System.out.print(element + " ");
        }
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
        partition(ar);
    }    
}

