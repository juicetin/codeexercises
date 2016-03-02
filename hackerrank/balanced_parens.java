import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class balanced_parens {

    public static void popParensIfMatching(Stack<Character> st, char c) {
        switch (c) {
            case '}': 
                if (!st.empty() && st.peek() == '{') {
                    st.pop();
                } 
                else {
                    st.push(new Character(c));
                }
                break;
            case ']':
                if (!st.empty() && st.peek() == '[') {
                    st.pop();
                }
                else {
                    st.push(new Character(c));
                }
                break;
            case ')':
                if (!st.empty() && st.peek() == '(') {
                    st.pop();
                }
                else {
                    st.push(new Character(c));
                }
                break;
            default:
                st.push(new Character(c));
                break;
        }
    }

    public static String balancedParens(String sequence) {
        Stack<Character> parensStack = new Stack<Character>();
        for (int i = 0; i < sequence.length(); ++i) {
            char cur = sequence.charAt(i);
            popParensIfMatching(parensStack, cur);
        }

        if (parensStack.empty()) {
            return new String("YES");
        }
        return new String("NO");
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int cases = Integer.parseInt(br.readLine());
            String input;
            for (int i = 0; i < cases; ++i) {
                input = br.readLine();
                String balanced = balancedParens(input);
                System.out.println(balanced);
            }
        } catch (IOException err) { }
    }
}
