import sys
MAX_GROUP_SIZE = int(10e6 + 1)

def check_if_same_group(prev_num, cur_num):
    return prev_num + 1 == cur_num

def at_last_list_item(index, num_list):
    return index == len(num_list)-1

num_of_test_cases = int(input())
def find_smallest_consecutive_sublist(skill_list):
    smallest_group = MAX_GROUP_SIZE
    current_smallest_group = 1
    for cur_index in range(1, len(skill_list)):
        cur_num = skill_list[cur_index]
        prev_num = skill_list[cur_index-1]

        if check_if_same_group(prev_num, cur_num):
            current_smallest_group += 1
        elif not check_if_same_group(prev_num, cur_num):
            smallest_group = min(current_smallest_group, smallest_group)
            current_smallest_group = 1

    # check again to account for group ending at last number
    smallest_group = min(current_smallest_group, smallest_group)

    return smallest_group

for test_case in range(num_of_test_cases):
    numbers = list(map(int, input().split(' ')))[1:]
    numbers.sort()
    smallest_group = find_smallest_consecutive_sublist(numbers)
    print(smallest_group, numbers)
    print()
