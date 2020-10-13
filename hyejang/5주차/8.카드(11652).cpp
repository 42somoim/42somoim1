#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count;
	int cnt = 1, max = 0, index = 0;
	long long num[100001] = { 0 };

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> num[i];
	}
	sort(num, num + count);
	for (int i = 0; i < count - 1; i++)
	{
		if (num[i] == num[i + 1])
		{
			cnt++;
			if (cnt > max)
			{
				max = cnt;
				index = i;
			}
		}
		else
			cnt = 1;
	}
	cout << num[index] << '\n';
}