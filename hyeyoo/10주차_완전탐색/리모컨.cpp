#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int abs(int n) {
	return (n < 0) ? -n : n;
}

int nbr_len(int n) {
	int len = 0;
	if (n == 0)
		return 1;
	while (abs(n) > 0) {
		n /= 10;
		len++;
	}
	return len;
}

bool contains(int *broken, int size, int channel)
{
	if (channel == 0) {
		for (int i = 0; i < size; i++) {
			if (broken[i] == 0)
				return true;
		}
	}
	while (channel > 0) {
		int digit = channel % 10;
		for (int i = 0; i < size; i++) {
			if (broken[i] == digit)
				return true;
		}
		channel /= 10;
	}
	return false;
}

int		main(void)
{
	int target;
	int current = 100;
	int n_broken;
	int *broken;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> target >> n_broken;
	if (n_broken == 0) {
		int ans = min(nbr_len(target), abs(target - current));
		cout << ans << endl;
	} else if (n_broken == 10) { 
		cout << abs(target - current) << endl;
	} else if (target == current) {
		cout << 0 << endl;
	} else {
		broken = new int[n_broken];
		for (int i = 0; i < n_broken; i++)
			cin >> broken[i];
		int min_dist = INT_MAX;
		int start = current;

		/* 버튼을 누르고 +, -로 이동 */
		for (int channel = 0; channel <= 1000000; channel++) {
			if (contains(broken, n_broken, channel))
					continue;
			if (min_dist > abs(target - channel)) {
				min_dist = abs(target - channel);
				start = channel;
			}
		}

		int ans = nbr_len(start) + abs(target - start);
		/* 버튼을 안 누르고 +, -로 이동하는 게 더 빠른 경우 or 불가능한 경우 */
		if (ans > abs(target - current)) {
			cout << abs(target - current) << endl;
		} else { 
			cout << ans << endl;
		}
		delete[] broken;
	}
	return 0;
}
