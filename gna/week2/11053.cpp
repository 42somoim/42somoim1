#include <stdio.h>
int arr[1001];
int dp[1001];
int main()
{
    int N,M;
    int i,j;
    int min = 0;
    int max = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        dp[i] = 1;
        min=0;
        scanf("%d", &arr[i]);
        for (j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && min < dp[j])
            {
                min = dp[j];
            }
        }
        dp[i] = min + 1;
        if (max < dp[i])
            max = dp[i];
    }
    printf("%d", max);
}

