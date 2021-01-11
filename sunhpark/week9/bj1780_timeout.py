n = int(input());
arr = [list(map(int, input().split())) for _ in range(n)]

# 3^n 3^n 만큼이 모두 같은 숫자인지 확인한다.
# 만약 탐색 도중 아닌게 판별이 되면 탐색을 종료한다.
# 3^(n - 1) 크기로 줄여서 다시 확인한다.
# 탐색은 전 부분에 의해서 이루어 져야 한다.
# 리스트를 그만큼씩 자르는 법이 있나?
# 만약 3^0 이 되면 탐색하지 않은 부분에 대해서 값을 더하고 끝내준다.

cnt = [0, 0, 0]

def check_square(square) :
	current = square[0][0]
	for row in square :
		if len(set(row)) == 1 :
			if (current != row[0]) :
				return 0
		else :
		  return 0
	return 1

def split_square(square, w) :
	for i in range(len(square) - w + 1) :
		if (w != 1 and i % 3 != 0) :
			continue
		for j in range(len(square) - w + 1) :
			if (w != 1 and j % 3 != 0) :
				continue
			temp = []
			for row in square[i : i + w] :
				splited = row[j : j + w]
				temp.append(splited)
			if (check_square(temp)) :
				cnt[1 + temp[0][0]] += 1
				continue
			else :
				split_square(temp, int(w / 3))
				


if (check_square(arr)) :
	cnt[1 + arr[0][0]] += 1
else :
	split_square(arr, int(n / 3))

for c in cnt :
	print(c)
