def divisible_by_3_or_5 (num):
    return num % 3 == 0 or num % 5 == 0

def ari_sum_with_skip(num, skip):
    d = int((num-1)/skip)
    f = skip
    l = f + (d-1) * skip
    sum = int(d * (f + l) ) >> 1
    return sum

def fizz_buzz(n):
    sum = 0
    sum += ari_sum_with_skip(n, 3)
    sum += ari_sum_with_skip(n, 5)

    if n > 15:
        sum -= ari_sum_with_skip(n, 15)
    
    print (sum)
    
cases = int(input())

for i in range(0,cases):
    n = int(input())
    fizz_buzz(n)

