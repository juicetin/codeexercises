num_count = int(input())
nums = [int(str_int) for str_int in input().split()]

# Mean
mean = sum(nums)/num_count

# Median
nums.sort()
if num_count % 2 == 0:
    median = (nums[int(num_count/2)] + nums[int(num_count/2)-1])/2
else:
    median = nums[int(num_count)/2]

# Mode


print(mean)
print(median)
