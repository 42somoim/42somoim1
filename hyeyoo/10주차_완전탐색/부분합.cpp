#include <iostream>
#include <cstdint>
#include <climits>

using namespace std;

int N, S;
int arr[100001];

int		main(void)
{
	cin >> N >> S;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int s = 0, e = 0;
	int sum = 0;
	int ans = INT_MAX;

	while (e <= N) {
		if (sum >= S) {
			ans = min(ans, e - s);
			sum -= arr[s];
			s++;
		} else {
			if (e == N)
				break;
			sum += arr[e];
			e++;
		}
	}
	cout << (ans == INT_MAX ? 0 : ans) << endl;
	return 0;
}
