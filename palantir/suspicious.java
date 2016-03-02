import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class suspicious {

    // Stores the maximum amount spendable on a single transaction
    //  before it is marked as suspicious
    private static int suspiciousAmount = 3000;

    /*
     *  Obtains location from location-time string
     *  NOTE - would preferably create my own class to hold 'more' than
     *      just a key and a value here, but locked into static context
     *      from given constraints of using a single class
     */
    public static String getLocationFromMapValue(String value) {
        return value.split("\\|")[0];
    }

    public static String locationAndTimeToString(String location, int time) {
        return location + "|" + time;
    }

    /*
     *  Obtains time from location-time string
     *  NOTE - would preferably create my own class to hold 'more' than
     *      just a key and a value here, but locked into static context
     *      from given constraints of using a single class
     */
    public static int getTimeFromMapValue(String value) {
        return Integer.parseInt(value.split("\\|")[1]);
    }

    // TODO
    // Would refactor this more if had more time left
    public static void checkAllTransactions(String[] transactions, HashMap<String, Integer> suspiciousPeople, HashMap<String, String> lastTransactionLocationTime) {
        // Iterate over all transactions
        for (String transaction : transactions) {

            // Break string into parts and extract information
            // TODO would refactor to extract information in separate function:
            //  data layout could change in future
            String[] transactionParts = transaction.split("\\|");
            String name = new String(), location = new String();
            int dollarAmount = 0, minsSinceMidnight = 0;
            name = transactionParts[0];
            dollarAmount = Integer.parseInt(transactionParts[1]);
            location = transactionParts[2];
            minsSinceMidnight = Integer.parseInt(transactionParts[3]);

            // Check if there is a previous transaction by this person
            //  in a different location less than an hour ago
            boolean personExists = lastTransactionLocationTime.containsKey(name);
            boolean personSuspicious = suspiciousPeople.containsKey(name);
            // Don't need to check if person is already suspicious
            // TODO refactor this part out into another function - contains
            //  functionality that can be isolated into a unit test
            if (!personSuspicious && personExists) {

                // Pull relevant info from last transaction
                String lastLocationTime = lastTransactionLocationTime.get(name);
                String lastLocation = getLocationFromMapValue(lastLocationTime);
                int lastTime = getTimeFromMapValue(lastLocationTime);

                // Build relevant conditions
                boolean locationChanged = !lastLocation.equals(location);
                boolean lessThanHourElapsed = minsSinceMidnight - lastTime < 60;
                if (locationChanged && lessThanHourElapsed) {
                    // Only insert if person isn't already suspicious/don't update!
                    if (!suspiciousPeople.containsKey(name)) {
                        suspiciousPeople.put(name, lastTime);
                    }
                }
            }

            // Store location of last transaction
            lastTransactionLocationTime.put(name, 
                    locationAndTimeToString(location, minsSinceMidnight));

            // Check for suspicious amounts
            if (dollarAmount > suspiciousAmount) {
                // Only insert if person isn't already suspicious/don't update!
                if (!suspiciousPeople.containsKey(name)) {
                    suspiciousPeople.put(name, minsSinceMidnight);
                }
            }
        }
    }

    static String[] getSuspiciousList(String[] transactions) {

        // Map to hold suspicious people along with time they were first
        // marked as such
        HashMap<String, Integer> suspiciousPeople = new HashMap<>();

        // Map to hold name, location, and time data of transactions per person
        HashMap<String, String> lastTransactionLocationTime = new HashMap<>();

        // Process all transactions here
        checkAllTransactions(transactions, suspiciousPeople, lastTransactionLocationTime);

        // Convert back to array
        String [] suspiciousPeopleArray = new String[suspiciousPeople.size()];
        Map<Integer, String> sortedSuspiciousPeople = new TreeMap<>();

        // Reorder items into a tree map to sort by time
        for (String key : suspiciousPeople.keySet()) {
            sortedSuspiciousPeople.put(suspiciousPeople.get(key), key);
        }

        // Put suspicious people (now ordered by time) into the array to return
        int i = 0;
        for (Map.Entry<Integer, String> entry: sortedSuspiciousPeople.entrySet()) {
            String key = entry.getValue();
            suspiciousPeopleArray[i++] = key;
        }
        return suspiciousPeopleArray;
    }

    public static void main (String args[] ) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int trxs = Integer.parseInt(br.readLine());
            String[] transactions = new String[trxs];
            for (int i = 0; i < trxs; ++i) {
                transactions[i] = br.readLine();
            }

            String[] suspiciousList = getSuspiciousList(transactions);
            for (String person : suspiciousList) {
                System.out.println(person);
            }
        } catch(IOException error) {
        }
    }
}
