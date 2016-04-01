import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class PalindromeIndex {

    public static boolean isPalindrome(String str) {
        for (int i = 0; i < str.length(); ++i) {
            if (str.charAt(i) != str.charAt(str.length()-i-1)) {
                return false;
            }
        }
        return true;
    }

    public static int checkForRemoval(String str, int index) {
        int front = index;
        int back = str.length() - index - 1;

        // When there is a palindrome-killing char mismatch
        if (str.charAt(front) != str.charAt(back)) {
            StringBuilder sb = new StringBuilder(str);
            sb.deleteCharAt(back);
            String newPalindrome = sb.toString();

            // Check which removal will result in getting a palindrome
            if (isPalindrome(newPalindrome)) {
                return back;
            } else {
                return front;
            }
        }

        return -1;
    }

    public static int palindromeRemoveIndex(String str) {

        // Zone into the middle char from both sides
        for (int i = 0; i < str.length()/2; ++i) {
            int removeIndex = checkForRemoval(str, i);
            if (removeIndex != -1) {
                return removeIndex;
            }
        }

        return -1;
    }

    public static void main (String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            int cases = Integer.parseInt(br.readLine());
            for (int i = 0; i < cases; ++i) {
                int removeIndex = palindromeRemoveIndex(br.readLine());
                System.out.println(removeIndex);
            }
        } catch (IOException error) {}
    }
}
