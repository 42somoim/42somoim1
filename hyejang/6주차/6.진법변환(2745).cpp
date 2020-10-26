#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int base, result = 0;
	string num, alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cin >> num;
	cin >> base;
	int tmp = base;
	for (int i = 0; i < num.length(); i++)
	{
		for (int j = 0; j <= base; j++)
		{
			if (alphabet[j] == num[i])
			{
				if (i != 0)
				{
					result = ((result * base) + j);
				}
				else
				{
					result = j;
				}
			}
		}
	}
	cout << result;
}
//A 10 => 10
//A 11 => 10
//B 12 => 10
//B 13 => 10