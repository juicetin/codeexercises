fib_arr = [0] * 1001

def fib_dp(n):
	if n <= 0 or n > 1000:
		return "Outside allowed range"
	elif n == 1:
		return fib_arr[1]
	elif n== 2:
		return fib_arr[2]

	if fib_arr[n-1] == 0:
		fib_arr[n-1] = fib_dp(n-1)
	if fib_arr[n-2] == 0:
		fib_arr[n-2] = fib_dp(n-2)

	fib_arr[n] = fib_arr[n-1] + fib_arr[n-2]
	return fib_arr[n]
	
def fib_rec(n):
	if n <= 0 or n > 1000:
		return "Outside allowed range"
	elif n == 1:
		return 1
	elif n == 2:
		return 2
	
	return fib_rec(n-1) + fib_rec(n-2)

def fib_iter(n):
	if n <= 0 or n > 1000000:
		return "Outside allowed range"
	elif n == 1:
		return 1
	elif n == 2:
		return 1

	i = 0
	a = 0
	b = 1
	while i != n-1:
		tmp = b
		b = a + b				
		a = tmp
		i+=1
	return b

#Main
fib_arr[1] = 1
fib_arr[2] = 1

fib_n = input()
print (fib_iter(int(fib_n)))
