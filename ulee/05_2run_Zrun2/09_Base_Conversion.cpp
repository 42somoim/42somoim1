#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	int m;
	int num;
	int decimal;
	int i;

	decimal = 0;
	cin >> a >> b;
	cin >> m;

	while (m--)
	{
		cin >> num;
		decimal += num * pow(a, m);
	}
	stack<int> s;
	i = 0;
	while (decimal)
	{
		s.push(decimal % b);
		decimal /= b;
		i++;
	}
	for (int j = 0; j < i; j++)
	{
		if (j == 0)
			cout << s.top();
		else
			cout << ' ' << s.top();
		s.pop();
	}
	return (0);
}
