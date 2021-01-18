# Sick Knight is placed in the left-bottom of the N x M size board.
# it can move :
## 2 up, 1 right
## 1 up, 2 right
## 1 down, 2 right
## 2 down, 1 right

# it want to move at most times.
# if movement is lower than 4, it need to use all the four ways to move
# if not, it doesn't need to use all of them.

# Maximum Val of Movement ?

N, M = map(int, input().split());

# 세로 길이가 충분한 경우 ( N >= 3 )
if N >= 3 :
	if M >= 6 :
		print(M - 2)
	else :
		if M >= 4 :
			print('4')
		else :
			print(M)
elif N == 2 :
	if M >= 8 :
		print('4');
	else :
		if M % 2 :
			print(M // 2 + 1)
		else :
			print(M // 2)
else : 
	print('1')
