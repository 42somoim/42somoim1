#include <iostream>

using namespace std;

const int MAX = 100000;
int main(void)
{
	int N, S, i;
	int l = 0, h = 0, result = MAX, sum = 0;
	int arr[MAX];

	cin >> N >> S;
	for (i = 0; i < N; i++)
		cin >> arr[i];

	while (1)
	{
		if (sum >= S)
		{
			result = min(result, h - l);
			sum -= arr[l++];
		}
		else if (h == N)
			break;
		else
			sum += arr[h++];
	}
	if (result == MAX)
		cout << 0;
	else
		cout << result;
	return 0;
}