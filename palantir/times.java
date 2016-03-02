import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class times {
    static int minutesInHalfADay = 60 * 12;
    static int minutesInADay = 60 * 24;
    static int getTimeDifference(String time1Str, String time2Str) {
        long diffInMinutes = 0;
        try {
            // Create parser/formatter
            SimpleDateFormat formatter = new SimpleDateFormat("HH:mm");

            // Convert strings to java dates
            Date time1 = formatter.parse(time1Str);
            Date time2 = formatter.parse(time2Str);

            // Get raw difference in minutes
            long diffInMillis = time2.getTime() - time1.getTime();
            diffInMinutes = diffInMillis/(1000 * 60);

            // Account for ordering of times
            if (diffInMinutes < 0) {
                diffInMinutes = -diffInMinutes;
            }

            // Account for cyclical difference
            if (diffInMinutes > minutesInHalfADay) {
                diffInMinutes = minutesInADay - diffInMinutes;
            }
        } catch(ParseException e) { }
        return (int)diffInMinutes;
    }

    static int getMinTimeDifference(String[] times) {
        // Max minutes in a day - safe max starting value
        int min = 60 * 24;

        // Naive O(n^2) approach
        // TODO would fix this to use at least an O(nlogn) approach
        //  if I hadn't spent so long on the other question
        for (int i = 0; i < times.length-1; ++i) {
            for (int j = i+1; j < times.length; ++j) {
                int curDiff = getTimeDifference(times[i], times[j]);
                if (curDiff < min) {
                    min = curDiff;
                }
            }
        }        
        return min;
    }

    public static void main (String args[]) {
        int diff = getTimeDifference(new String("13:47"), new String("13:27"));
        System.out.println(diff);
    }
}
