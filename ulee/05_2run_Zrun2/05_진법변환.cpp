#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	int b;
	int sum = 0;

	cin >> s >> b;
	for (int i = 0; i < s.length(); ++i)
	{
		if ('0' <= s[i] && s[i] <= '9')
			sum = sum * b + s[i] - 48;
		else  sum = sum * b + s[i] - 55;
	}
	cout << sum << "\n";
	return (0);
}
