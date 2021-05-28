#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s, result;
	int len;

	cin >> s;
	len = s.length();

	if (len % 3 == 1)
		printf("%d", s[0] - '0');
	else if (len % 3 == 2)
		printf("%d", (s[0] - '0') * 2 + (s[1] - '0'));
	for (int i = len % 3; i < len; i += 3)
		printf("%d", (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0'));
}
