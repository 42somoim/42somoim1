#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N, M, K;

	cin >> N >> M >> K;

	cout << min(min(N/2, M), (N + M - K) / 3);
	return 0;
}