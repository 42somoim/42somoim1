#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	string N;
	vector<int> v;
	long long sum = 0;
	bool zero = false;

	cin >> N;
	for (int i = 0; i < N.length(); ++i) {
		int tmp = N[i] - '0';
		if (!tmp) zero = true;
		sum += tmp;
		v.push_back(tmp);
	}
	if (!zero || sum % 3 != 0)
		cout << -1;
	else
	{
		sort(v.begin(), v.end());
		for (int i = v.size() - 1; i >= 0; --i)
			cout << v[i];
	}
	return 0;
}