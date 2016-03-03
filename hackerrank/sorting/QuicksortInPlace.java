import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class QuicksortInPlace {

    /*
     *  Swap two elements in an array
     */
    public static void swap(int[] arr, int a, int b) {
        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }

    /*
     *  Partition an array given two boundary indices
     */
    public static int partition(int[] arr, int left, int right) {
        int pivot = arr[right];
        int index = left;
        for (int i = left; i < right; ++i) {
            if (arr[i] <= pivot) {
                // Swap arr[index] and arr[i]
                swap(arr, index, i);
                index++;
            }
        }

        // Swap the 'beginning' of the 'larger' section with the pivot
        //  currently at the end of the array
        swap(arr, index, right);
        printArray(arr);
        return index;
    }

    public static void quicksortRecursive(int[] arr, int left, int right) {
        if (left < right) {
            int p = partition(arr, left, right);
            quicksortRecursive(arr, left, p-1);
            quicksortRecursive(arr, p+1, right);
        }
    }

    public static void quicksort(int[] arr) {
        quicksortRecursive(arr, 0, arr.length-1);
    }

    static void printArray(int[] ar) {
        for(int n: ar){
            System.out.print(n+" ");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] ar = new int[n];
        for(int i=0;i<n;i++){
            ar[i]=in.nextInt(); 
        }
        quicksort(ar);
    }
}
