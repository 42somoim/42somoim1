#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int one(int num1, int num2)
{
	int tmp;
	while (num1 != 0)
	{
		tmp = num2 % num1;
		num2 = num1;
		num1 = tmp;
	}
	return num2;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t, count, num[100] = { 0 };
	long long sum;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		sum = 0;
		cin >> count;
		for (int j = 0; j < count; j++)
		{
			cin >> num[j];
		}
		sort(num, num + count);
		for (int j = 0; j < count; j++)
		{
			for (int k = j; k < count; k++)
			{
				if (k + 1 != count)
				{
					sum += one(num[j], num[k + 1]);
				}
			}
		}
		cout << sum << "\n";
	}
}