#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}
int main(void)
{
	int N, K;
	int ans = 0;

	cin >> N >> K;
	
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	sort(A.begin(), A.end(), cmp);
	for (int i = 0; i < N; ++i) {
		while (K - A[i] >= 0) {
			ans++;
			K -= A[i];			
		}
	}
	cout << ans;
	return 0;
}