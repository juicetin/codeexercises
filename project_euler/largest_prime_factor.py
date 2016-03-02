import math

cases = int(input())

def is_prime_dumb(n):
    if n <= 3:
        return True
    if n % 2 == 0:
        return False

    ceil = int(math.sqrt(n)) + 1
    for i in range(3, ceil+1, 2):
        if n % i == 0:
            return False
    return True

def largest_prime_factor(n):
    if n <= 3:
        return 3;
    ceil = int(math.sqrt(n))+1
    largest = 1;
    for i in range(3,int(n/2)+1,2):
        if n % i ==0 and is_prime_dumb(i):
            largest = i

    if is_prime_dumb(n):
        return n

    return largest

for i in range(0, cases):
    n = int(input())
    lpf = largest_prime_factor(n)
    print(lpf)
