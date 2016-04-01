import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class BiggerIsGreater {

    static void swap(String str, int i, int j) {
        char tmp = str.charAt(i);
        StringBuilder sb = new StringBuilder(str);
        sb.setCharAt(i, str.charAt(j));
        sb.setCharAt(j, tmp);
        str = sb.toString();
    }

    static String nextLargestString(String str) {
        for (int i = str.length()-1; i >= 1; i--) {
            if (str.charAt(i) > str.charAt(i-1)) {
                swap(str, i, i-1);
                return str;
            }
        }
        return new String("no answer");
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            int cases = Integer.parseInt(br.readLine());
            for (int i = 0; i < cases; ++i) {
                String result = nextLargestString(br.readLine());
                System.out.println(result);
            }
        } catch(IOException error) {}
    }
}
