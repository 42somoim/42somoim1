#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check(string str)
{
	int len = str.length();
	stack<char> s;

	for (int i = 0; i < len; i++)
	{
		char c = str[i];
		if (c == '(')
			s.push(c);
		else
		{
			if (!s.empty())
				s.pop();
			else
				return false;
		}
	}
	return s.empty();
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (check(str))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}