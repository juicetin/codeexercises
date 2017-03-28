staircase_height = int(input())
space_count = staircase_height - 1
hash_count = 1
for i in range(staircase_height):
    print(' ' * space_count, end = '')
    print('#' * hash_count)
    space_count -= 1
    hash_count += 1
