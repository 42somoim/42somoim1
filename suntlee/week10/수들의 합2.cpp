#include <iostream>

using namespace std;

int main(void)
{
	int N, M, i;
	int l = 0, h = 0, cnt = 0, sum = 0;
	int arr[10ㅋㅋ000];

	cin >> N >> M;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	
	while (1)
	{
		if (sum >= M)
			sum -= arr[l++];
		else if (h == N)
			break;
		else
			sum += arr[h++];
		
		if (sum == M)
			cnt++;
	}
	cout << cnt;
	return 0;
}