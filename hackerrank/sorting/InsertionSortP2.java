import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class InsertionSortP2 {

    /*
     *  Print array
     */
    public static void printArr(int[] ar) {
        for (int i = 0; i < ar.length; ++i) {
            System.out.print(ar[i] + " ");
        }
        System.out.println();
    }

    public static void sortSingle(int[] ar, int insertIndex) {
        int insertNum = ar[insertIndex];
        int index = insertIndex - 1;

        // Shift
        while (index >= 0 && ar[index] > insertNum)  {
            ar[index+1] = ar[index];
            index--;
        }

        // Replace
        ar[index+1] = insertNum;
    }

    /*
     *  Sort array
     */
    public static void insertionSortPart2(int[] ar) {
        for (int i = 1; i < ar.length; ++i) {
            sortSingle(ar, i);
            printArr(ar);
        }
    }

    public static void main (String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            int length = Integer.parseInt(br.readLine());
            int[] ar = new int[length];

            String[] numsStrings = br.readLine().split(" ");
            for (int i = 0; i < length; ++i) {
                ar[i] = Integer.parseInt(numsStrings[i]);
            }
            insertionSortPart2(ar);

        } catch (IOException error) {}
    }
}
