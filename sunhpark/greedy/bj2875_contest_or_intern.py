# 2 women & 1 man
# N women & M men
# K students must participate internship
# intern students cannot participate the contest

# we want to make team as much as possible

# INPUT
# N, M, K

N, M, K = map(int, input().split())

# because we need more women than men
# first we check the number of women.

team = 0
internship = 0

women_duo = N // 2
women_rest = N % 2

men_rest = 0

while (1) :
	if (women_duo <= M) :
		men_rest = M - women_duo
		internship = men_rest + women_rest
		if internship >= K :
			team = women_duo
			break
	women_duo -= 1
	women_rest += 2

print(team)

	

