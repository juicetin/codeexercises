#!/bin/python3

import sys
import math

def sieve_of_eratosthenes(n):
    pass

def is_prime(n):
    if n == 1:
        return False
    elif n == 2:
        return True
    elif n % 2 == 0:
        return False
    else:
        for i in range(3, math.ceil(math.sqrt(n))+1, 2):
            if n % i == 0:
                return False

    return True

def is_megaprime(n):
    if is_prime(n) is not True:
        return False

    for digit in str(n):
        if is_prime(int(digit)) is not True:
            return False

    return True

first,last = input().strip().split(' ')
first,last = [int(first),int(last)]
# your code goes here

megaprime_count = 0
for i in range(first, last+1):
    if is_megaprime(i):
        megaprime_count += 1

print(megaprime_count)
