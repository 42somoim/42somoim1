#include <unistd.h>
#include <stdio.h>

void solution(int n)
{
	int square[1001];
	square[1] = 1;
	square[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		square[i] = (square[i-1] + square[i-2]) % 10007;
	}
	printf("%d", square[n]);
}

int main() 
{
	int n;
	scanf("%d", &n);
	solution(n);
}
