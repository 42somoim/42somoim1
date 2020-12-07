#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 4000000;
int arr[MAX];
vector<int> prime;

void erasthones(void)
{
	arr[0] = arr[1] = -1;
	for (long long i = 2; i < MAX; i++)
		arr[i] = i;
	for (long long i = 2; i < MAX; i++)
		if (arr[i] == i)
			for (long long j = i * i; j < MAX ; j+= i)
				arr[j] = -1;
	for (long long i = 0; i < MAX; i++)
		if (arr[i] == i)
			prime.push_back(i);
}

int main(void)
{
	int N;

	cin >> N;

	erasthones();

	int l = 0, h = 0, sum = 0, cnt = 0;

	while (1)
	{
		if (sum >= N)
			sum -= prime[l++];
		else if (h == prime.size())
			break;
		else
			sum += prime[h++];
		if (sum == N)
			cnt++;
	}
	cout << cnt;
	return 0;
}

