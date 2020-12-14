#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX = 40;
int N, S;
int arr[MAX];

void subsum(int idx, int end, int sum, vector<int> &list)
{
	if (idx == end)
	{
		list.push_back(sum);
		return ;
	}
	subsum(idx + 1, end, sum, list);
	subsum(idx + 1, end, sum + arr[idx], list);
}

int main(void)
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	vector<int> left;
	vector<int> right;

	subsum(0, N / 2, 0, left);
	subsum(N / 2, N, 0, right);

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	long ans = 0;
	int L = 0;
	int R = right.size() - 1;

	while (L < left.size() && R >= 0)
	{
		long valL = left[L];
		long valR = right[R];

		if ((valL + valR) == S)
		{
			long cntL = 0, cntR = 0;
			while (L < left.size() && valL == left[L])
			{
				L++;
				cntL++;
			}
			while (R >= 0 && valR == right[R])
			{
				R--;
				cntR++;
			}
			ans += (cntL * cntR);
		}
		else if ((valL + valR) > S)
			R--;
		else
			L++;
	}
	if (S == 0)
		ans--;
	cout << ans;
}