[size, left_shift] = list(map(int, input().split(' ')))
numbers = list(map(int, input().split(' ')))

left_shift = left_shift % size
shifted_numbers = numbers[left_shift:] + numbers[:left_shift]
print(' '.join(map(str, shifted_numbers)))
