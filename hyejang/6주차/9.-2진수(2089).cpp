#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num;
	string result;

	cin >> num;
	if (num == 0)
	{
		cout << num << "\n";
	}
	while (num != 0)
	{
		if (num % 2 == 0)
		{
			result += "0";
			num = -(num / 2);
		}
		else
		{
			if (num > 0)
			{
				num = -(num / 2);
			}
			else
			{
				num = (-num + 1) / 2;
			}
			result += "1";
		}
	}
	for (int i = result.length() - 1; i >= 0; i--)
	{
		cout << result[i];
	}
}