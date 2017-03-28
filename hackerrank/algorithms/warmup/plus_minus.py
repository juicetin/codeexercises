number_count = int(input())
numbers = map(int, input().split(' '))
pos_num_count = 0
neg_num_count = 0
nil_num_count = 0
for number in numbers:
    if number > 0:
        pos_num_count += 1
    elif number == 0:
        nil_num_count += 1
    elif number < 0:
        neg_num_count += 1

print(pos_num_count/number_count)
print(neg_num_count/number_count)
print(nil_num_count/number_count)
