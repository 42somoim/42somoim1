N = int(input());
arr = [];
result = [];

for _ in range(N) :
	arr.append(list(input()));

def check(x, y, n) :
	current = arr[x][y]
	for i in range(n) :
		for j in range(n) :
			if (current != arr[x + i][y + j]) :
				return False
	return True

def devide(x, y, n) :
	if check(x, y, n) :
		result.append(arr[x][y])
		return
	result.append('(')
	for i in range(2) :
		for j in range(2) :
			devide(x + i * n//2, y + j * n//2, n//2)
	result.append(')')

devide(0, 0, N)

print(''.join(result))
