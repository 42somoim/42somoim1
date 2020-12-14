#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int pizza;
	cin >> pizza;
	
	int M, N;
	cin >> M >> N;

	vector<int> A(M), B(N);
	for (int i = 0; i < M; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	
	vector<int> v(1, 0), v2(1, 0);
	int low = 0, high = 0;
	int sum = 0;
	while (low < A.size())
	{
		sum += A[high++];
		if (sum <= pizza)
			v.push_back(sum);
		else
		{
			low++;
			high = low;
			sum = 0;
		}

		if (high == A.size())
			high = 0;
		if ((!low && !high) || high + 1 == low)
		{
			low++;
			high = low;
			sum = 0;
		}
	}
	low = 0, high = 0, sum = 0;
	while (low < B.size())
	{
		sum += B[high++];
		if (sum <= pizza)
			v2.push_back(sum);
		else
		{
			low++;
			high = low;
			sum = 0;
		}

		if (high == B.size())
			high = 0;
		if ((!low && !high) || high + 1 == low)
		{
			low++;
			high = low;
			sum = 0;
		}
	}
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());
    int result = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int low = lower_bound(v2.begin(), v2.end(), pizza - v[i]) - v2.begin();
		int high = upper_bound(v2.begin(), v2.end(), pizza - v[i]) - v2.begin();
		result += high - low;
	}
	cout << result << '\n';
	return 0;
}