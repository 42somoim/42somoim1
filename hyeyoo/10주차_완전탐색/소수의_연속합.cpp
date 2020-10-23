#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_prime[4000001];
int N;

int		main(void)
{
	cin >> N;
	fill_n(is_prime, 4000001, true);

	for (int i = 2; i <= N; i++) {
		if (!is_prime[i])
			continue;
		for (int j = i + i; j <= N; j += i) {
			is_prime[j] = false;
		}
	}

	vector<int> prime;
	for (int i = 2; i <= N; i++) {
		if (is_prime[i]) {
			prime.push_back(i);
		}
	}

	size_t ans = 0;
	size_t s = 0;
	size_t e = 0;
	size_t sum = 0;
	while (e <= prime.size()) {
		if (sum >= N) {
			if (sum == N) {
				ans++;
			}
			sum -= prime[s];
			s++;
		} else {
			if (e == prime.size())
				break;
			sum += prime[e];
			e++;
		}
	}
	cout << ans << endl;
	return 0;
}
