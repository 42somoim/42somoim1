#include <iostream>
#include <stack>
#include <string>

using namespace std;

int check(string str)
{
	int len = str.length();
	stack<char> s;
	int result = 0;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else
		{
			s.pop();
			if (str[i-1] == '(')
				result += s.size();
			else
				result++;
		}
	}
	return result;
}

int main()
{
	string str;
	cin >> str;
	cout << check(str);
	return 0;
}