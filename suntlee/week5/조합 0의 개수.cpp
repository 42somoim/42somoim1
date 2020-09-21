#include <iostream>
#include <algorithm>

using namespace std;

long long divide(int num, int divisor)
{
	long long cnt = 0;
	for (long long i = divisor; i <= num; i *= divisor)
		cnt += num / i;
	return cnt;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << min(divide(n, 5) - (divide(m, 5) + divide(n-m, 5)), divide(n, 2) - (divide(m, 2) + divide(n-m, 2)));
	return 0;
}