#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count, value;
	int cnt = 1, max = 0, index = 0;
	int num[5000001] = { 0 };

	cin >> count;
	cin >> value;
	for (int i = 0; i < count; i++)
	{
		cin >> num[i];
	}
	sort(num, num + count);

	cout << num[value - 1] << '\n';
}