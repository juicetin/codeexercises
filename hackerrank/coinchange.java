import java.io.*;
import java.util.*;

public class coinchange {

    // public static void changeCombos(int change, int[] coins) {
    //     int[] changeTable = new int[change+1];
    //     Set<Integer> coinsHash = new TreeSet();
    //     for (int i = 0; i < coins.length; ++i) {
    //         coinsHash.add(coins[i]);
    //     }

    //     for (int cur_change = 1; cur_change <= change; ++cur_change) {

    //         // Possible combinations for current change value
    //         int combosForChangeValue = 0;

    //         // Change value can be obtained by taking coin of this value
    //         if (coinsHash.contains(cur_change)) {
    //             // System.out.println("For change value " + cur_change + " adding 1 because coin exists for this value");
    //             combosForChangeValue++;
    //         }

    //         // Iterate through coins, checking only those
    //         //  >= half the value being checked (don't double up)
    //         Iterator<Integer> itr = coinsHash.iterator();
    //         int threshold = cur_change%2 == 0 ? cur_change/2 : cur_change/2+1;
    //         while(itr.hasNext()) {
    //             int coin = itr.next();
    //             if (coin <= cur_change && coin >= threshold || !coinsHash.contains(cur_change - coin)) {
    //                 // System.out.println("for change value " + 
    //                 //         cur_change + " checking coin " + coin + " with threshold " + threshold);

    //                 // Add possible values onto current subtotal
    //                 //  for sums
    //                 int remainder = cur_change - coin;
    //                 if (remainder > 0) {
    //                     combosForChangeValue += changeTable[remainder];
    //                     // System.out.println("checking combos for " + coin + " with remainder " + remainder + " adding " + changeTable[remainder]);
    //                 }
    //             }
    //         }
    //         System.out.println("for change value " + cur_change + " , there are " + combosForChangeValue + " combos");
    //         changeTable[cur_change] = combosForChangeValue;

    //         // for (int j = 1; j <= change; ++j) {
    //         //     System.out.print(changeTable[j] + " ");
    //         // } System.out.println();
    //     }

    //     System.out.println(changeTable[change]);
    // }

    public static void count(int S[], int m, int n) {
        int table[] = new int[n+1];

        table[0] = 1;
        // Iterate through coins available
        for (int i = 0; i < m; ++i) {

            // Iterate from picked coin up until change value
            for (int j = S[i]; j <= n; ++j) {

                // Add value at (change value - current coin)
                //  to current change value index
                table[j] += table[j-S[i]];
            }

            // for (int j = 0; j < n+1; ++j) {
            //     System.out.print(table[j] + " ");
            // } System.out.println();
        }

        System.out.println(table[n]);
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String input;
            int change, coinCount;
            input = br.readLine();
            change = Integer.parseInt(input.split(" ")[0]);
            coinCount = Integer.parseInt(input.split(" ")[1]);

            int coins[] = new int[coinCount];
            String coinsString = br.readLine();
            String coinsStringList[] = coinsString.split(" ");
            for (int i = 0; i < coinCount; ++i) {
                coins[i] = Integer.parseInt(coinsStringList[i]);
            }

            // changeCombos(change, coins);
            count (coins, coinCount, change);

        } catch(IOException i) {}
    }
}
