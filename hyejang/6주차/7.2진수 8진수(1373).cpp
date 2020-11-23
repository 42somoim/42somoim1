#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count = 0, binary = 1, sum = 0;
	string num, result;
	
	cin >> num;
	for (int i = num.length() - 1; i >= 0; i--)
	{
		if (count == 3)
		{
			count = 0;
			binary = 1;
			result += to_string(sum);
			sum = 0;
		}
		if (num[i] == '1')
		{
			sum += binary;
		}
		count++;
		binary = binary << 1;
	}

	if (num.length() <= 3 || sum != 0)
	{
		result += to_string(sum);
	}
	for (int i = result.length() - 1; i >= 0; i--)
	{
		cout << result[i];
	}
}