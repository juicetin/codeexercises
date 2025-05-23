import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class pairs{
    static int pairs(int[] a,int k) {
        /* Complete this function */
        Set<Integer> uniques = new HashSet<Integer>();
        int diffKCount = 0;
        for (int num : a) {
            if (uniques.contains(num+k)) {
                diffKCount++;
            }
            if (uniques.contains(num-k)) {
                diffKCount++;
            }
            uniques.add(num);
        }
        return diffKCount;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int res;

        String n = in.nextLine();
        String[] n_split = n.split(" ");

        int _a_size = Integer.parseInt(n_split[0]);
        int _k = Integer.parseInt(n_split[1]);

        int[] _a = new int[_a_size];
        int _a_item;
        String next = in.nextLine();
        String[] next_split = next.split(" ");

        for(int _a_i = 0; _a_i < _a_size; _a_i++) {
            _a_item = Integer.parseInt(next_split[_a_i]);
            _a[_a_i] = _a_item;
        }

        res = pairs(_a,_k);
        System.out.println(res);
    }
}

