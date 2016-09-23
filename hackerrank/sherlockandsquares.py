import math

def square_nums_between(a, b):
    cur_num = math.ceil(math.sqrt(a))
    count = 0
    while cur_num**2 <= b:
        count += 1
        cur_num += 1
    return count

num_lines = int(input())
for i in range(num_lines):
    a, b = list(map(int, input().split(' ')))
    print(square_nums_between(a, b))
