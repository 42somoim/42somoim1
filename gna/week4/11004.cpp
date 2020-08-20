
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	vector<long long> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &v[i]);
	}
	sort(v.begin(), v.end());
	printf("%lld\n", v[K - 1]);
	return 0;
}
