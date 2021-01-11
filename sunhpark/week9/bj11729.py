def min_hanoi(n : int) :
	if n == 1 :
		return 1
	return 1 + min_hanoi(n-1) * 2

def route_hanoi(n: int, a: int, b: int, c: int) :
	if n == 1 :
		print(str(a) + " " + str(c))
	else :
		route_hanoi(n-1, a, c, b)
		route_hanoi(1, a, b, c)
		route_hanoi(n-1, b, a, c)

n = int(input())
print(min_hanoi(n))
route_hanoi(n, 1, 2, 3)
