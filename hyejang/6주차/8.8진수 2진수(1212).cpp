#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string num, result;
	
	cin >> num;
	for (int i = 0; i <= num.length() - 1; i++)
	{
		if (num[i] == '0' && i == 0)
		{
			result += "0";
		}
		else if (num[i] == '0')
		{
			result += "000";
		}
		if (num[i] == '1' && i == 0)
		{
			result += "1";
		}
		else if (num[i] == '1')
		{
			result += "001";
		}
		if (num[i] == '2' && i == 0)
		{
			result += "10";
		}
		else if (num[i] == '2')
		{
			result += "010";
		}
		if (num[i] == '3' && i == 0)
		{
			result += "11";
		}
		else if (num[i] == '3')
		{
			result += "011";
		}
		if (num[i] == '4')
		{
			result += "100";
		}
		if (num[i] == '5')
		{
			result += "101";
		}
		if (num[i] == '6')
		{
			result += "110";
		}
		if (num[i] == '7')
		{
			result += "111";
		}
	}
	cout << result;
}