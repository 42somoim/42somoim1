#include <iostream>
using namespace std;

int dp[1001];

int tile(int n)
{
	if(n==1) return 1;
	else if(n==2) return 2;
	else if(dp[n]>0) return dp[n]; //기존에 구한 값을 바로 리턴.
	else
	{
		dp[n] = (tile(n-1) + tile(n-2))%10007;
		return dp[n];
	}
}

int main(void)
{
	int num=0;

	cin >> num;
	cout << tile(num);
	
	return 0;
}
