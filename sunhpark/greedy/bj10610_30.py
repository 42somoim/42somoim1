# want to make 30's multiple with a number 'N'
# Example : 30 input => 30 output, 102 input -> 210 output
# if not, print -1

# 30's multipe : the last one must be '0'. so if there is not 0 => -1

N = input()

def sumOfNum(num) : 
	each = list(num);
	result = 0;

	for n in each : 
		result += int(n);
	return result;

if (N.find('0') == -1 or sumOfNum(N) % 3 != 0) :
	print('-1')
else :
	each = list(N)
	each.sort(reverse=True)
	num = "".join(each)
	print(num)
