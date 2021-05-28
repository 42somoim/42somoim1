#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s, octal;
	int num;
	bool flag = false;

	cin >> s;

	if (s[0] == '0')
	{
		cout << '0'; return (0);
	}

	for (int i = 0; s[i]; i++)
	{
		num = s[i] - '0';
		octal += to_string(num / 4);
		octal += to_string(num % 4 / 2);
		octal += to_string(num % 4 % 2 / 1);
	}
	for (int i = 0; octal[i]; ++i)
	{
		if (octal[i] == '1')
		{
			cout << octal[i]; flag = true;
		}
		else if (flag)
			cout << octal[i];
	}
	cout << "\n";
	return (0);
}
