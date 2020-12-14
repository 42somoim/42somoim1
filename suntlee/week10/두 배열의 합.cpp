#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long T;
	cin >> T;

	int N;
	cin >> N;

	vector<long long> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int M;
	cin >> M;

	vector<long long> B(M);
	for (int i = 0; i < M; i++)
		cin >> B[i];

	vector<long long> v, v2;
	for (int i = 0; i < N; i++)
	{
		long long sum = A[i];
		v.push_back(sum);
		for (int j = i + 1; j < N; j++)
		{
		sum += A[j];
		v.push_back(sum);
		}
	}
 
	for (int i = 0; i < M; i++)
	{
		long long sum = B[i];
		v2.push_back(sum);
		for (int j = i + 1; j < M; j++)
		{
			sum += B[j];
			v2.push_back(sum);
		}
	}

	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	long long result = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int low = lower_bound(v2.begin(), v2.end(), T - v[i]) - v2.begin();
		int high = upper_bound(v2.begin(), v2.end(), T - v[i]) - v2.begin();
		result += high - low;
	}
	cout << result << "\n";
	return 0;

}
