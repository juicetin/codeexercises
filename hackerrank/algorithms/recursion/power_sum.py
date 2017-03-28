def count_sums(target_sum, power_list, index):
    if target_sum == 0:
        return 1
    elif target_sum < 0:
        return 0
    elif index == len(power_list):
        return 0

    count = 0
    count += count_sums(target_sum, power_list, index + 1)
    count += count_sums(target_sum - power_list[index], power_list, index + 1)

    return count

from math import ceil
number = int(input())
power = int(input())
root_of_target = ceil(number**(1/float(power))) + 1
nth_powers = list(map(lambda x: x**power, range(1, root_of_target)))
combinations = count_sums(number, nth_powers, 0)
print(combinations)
