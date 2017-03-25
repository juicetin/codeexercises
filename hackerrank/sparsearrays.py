from collections import OrderedDict

N = int(input())
strings = []
for i in range(N):
    strings.append(input())

Q = int(input())
queryMap = {}
queryStrings = []
for i in range(Q):
    currentStr = input()
    queryStrings.append(currentStr)
    queryMap[currentStr] = 0

for string in strings:
    if string in queryMap:
        queryMap[string] += 1

for queryString in queryStrings:
    print(queryMap[queryString])
