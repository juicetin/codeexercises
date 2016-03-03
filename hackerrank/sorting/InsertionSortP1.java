import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class InsertionSortP1 {

    public static void printArr(int[] ar) {
        for (int i = 0; i < ar.length; ++i) {
            System.out.print(ar[i] + " ");
        }
        System.out.println();
    }

    public static void insertIntoSorted(int[] ar) {

        int index = ar.length - 2;
        int insertNum = ar[ar.length - 1];

        // Shift
        while (index >= 0 && ar[index] > insertNum)  {
            ar[index+1] = ar[index];
            index--;
            printArr(ar);
        }
        
        // Replace
        ar[index+1] = insertNum;
        printArr(ar);
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
            insertIntoSorted(ar);

        } catch (IOException error) {}
    }
}
