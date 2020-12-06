#include <iostream>

using namespace std;

constexpr int MAX = 20;
int N, S, result = 0;
int arr[MAX];

void subsum(int idx, int sum)
{
	sum += arr[idx];
	if (idx >= N)
		return ;
	if (sum == S)
		result++;
	subsum(idx + 1, sum);
	subsum(idx + 1, sum - arr[idx]);
}

int main(void)
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	subsum(0, 0);
	cout << result;
}