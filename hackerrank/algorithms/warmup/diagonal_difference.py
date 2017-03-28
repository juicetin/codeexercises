matrix_size = int(input())
diag_index = 0
reverse_diag_index = matrix_size-1

diag_sum = 0
reverse_diag_sum = 0
for row in range(matrix_size):
    row_numbers = list(map(int, input().split(' ')))
    diag_sum += row_numbers[diag_index]
    reverse_diag_sum += row_numbers[reverse_diag_index]
    diag_index += 1
    reverse_diag_index -= 1

print(abs(diag_sum - reverse_diag_sum))

