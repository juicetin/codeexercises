import sys

def fib_mod(n, arr):
    if n <= 2:
        return arr[n-1];

    for x in range(2, n):
        next_num = arr[1] * arr[1] + arr[0]
        arr[0] = arr[1]
        arr[1] = next_num

    return arr[1]

nums = [int(s) for s in input().split(' ')]
fib_mod_arr = [nums[0], nums[1]]
n = nums[2]

print(fib_mod(n, fib_mod_arr))
