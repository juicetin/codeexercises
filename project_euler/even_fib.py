cases = int(input())

def even_fib_sum(n):
    dp = [1,1]
    if n <= 2:
        return 0

    total = 0
    i = 3
    while dp[1] < n:
        next_fib = sum(dp)
        dp[0] = dp[1]
        dp[1] = next_fib
        if next_fib % 2 == 0 and next_fib < n:
            total += next_fib
    return total

for i in range(0,cases):
    n = int(input())
    print (even_fib_sum(n))
