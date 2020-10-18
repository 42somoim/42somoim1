#include <iostream>
#include <stdlib.h>

int		N;

int     compare (const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int		main(void)
{
	scanf("%d", &N);

	int	arr[N];
	int temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
    qsort (arr, N, sizeof(int), compare);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}
	return (0);
}
