firstLine = map(int, input().split(' '))
listSize, numOfInstructions = firstLine

maxPrefixSumList = [0] * (listSize+1)
for i in range(numOfInstructions):
    instruction = map(int, input().split(' '))
    startIndex, endIndex, addAmount = instruction
    startIndex -= 1
    maxPrefixSumList[startIndex] += addAmount
    maxPrefixSumList[endIndex] -= addAmount


currentPrefixSum = 0
maxPrefixSum = 0
for number in maxPrefixSumList:
    currentPrefixSum += number
    if currentPrefixSum > maxPrefixSum:
        maxPrefixSum = currentPrefixSum

print(maxPrefixSum)
