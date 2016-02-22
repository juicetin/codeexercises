def longest_increasing_subsequence(arr):

    sub_LIS = []
    longest_LIS = 0;

    # Go through each number in array
    for num in arr:

        # Initial longest list is simply the current number
        cur_longest_sub_LIS = 0

        # Find the longest previous LIS whose last value is < num
        for i, sub_LIS_arr in enumerate(sub_LIS):

            # For a particular previous LIS, if its last value is smaller than num and length greater than current LIS
            # if len(sub_LIS_arr) > 0 and sub_LIS_arr[-1] <= num and len(sub_LIS_arr) > len(cur_longest_sub_LIS):
            if arr[i] <= num and sub_LIS_arr > cur_longest_sub_LIS:
                # Then update the new LIS
                cur_longest_sub_LIS = sub_LIS_arr

        # Finish processing LIS ending with current num
        # if (len(cur_longest_sub_LIS) == 0):
        if cur_longest_sub_LIS == 0:
            #cur_longest_sub_LIS = [num]
            cur_longest_sub_LIS = 1
        else:
            # cur_longest_sub_LIS.append(num)
            cur_longest_sub_LIS += 1

        sub_LIS.append(cur_longest_sub_LIS)
        # if len(cur_longest_sub_LIS) > len(longest_LIS):
        if cur_longest_sub_LIS > longest_LIS:
            longest_LIS = cur_longest_sub_LIS
    return longest_LIS

c = int(input())
arr = []
for x in range(0, c):
    arr.append(int(input()))

print ( longest_increasing_subsequence(arr)  )
