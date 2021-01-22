N = int(input())
pos_nums = []
neg_nums = []
result = 0
for _ in range(N) :
	num = int(input())
	if num > 0 :
		pos_nums.append(num)
	else : 
		neg_nums.append(num)

pos_nums.sort(reverse = True)
neg_nums.sort()

result = 0

for i in range(len(pos_nums)) :
	if i % 2 == 0 and i + 1 < len(pos_nums) :
		if pos_nums[i] == 1 or pos_nums[i + 1] == 1 :
			result += (pos_nums[i] + pos_nums[i + 1])
		else :
			result += (pos_nums[i] * pos_nums[i + 1])
	elif i == len(pos_nums) - 1 and len(pos_nums) % 2 == 1 :
		result += pos_nums[i]

for i in range(len(neg_nums)) :
	if i % 2 == 0 and i + 1 < len(neg_nums) :
		result += (neg_nums[i] * neg_nums[i + 1])
	elif i == len(neg_nums) - 1  and len(neg_nums) % 2 == 1 :
		result += neg_nums[i]

print(result)
