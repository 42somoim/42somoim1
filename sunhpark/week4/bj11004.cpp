#include <iostream>
#include <algorithm>

using	namespace std;
int		N, K;

int		main(void)
{
	scanf("%d %d", &N, &K);
	int	arr[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	printf("%d\n", arr[K - 1]);
	return (0);
}
