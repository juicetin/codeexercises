num_count = int(input())
nums = list(map(int, input().split()))
arr = [0] * 100

for i in range(0, num_count):
    arr[nums[i]] += 1

print(''.join('{} '.format(num[0]) * num[1] for num in enumerate(arr)))
