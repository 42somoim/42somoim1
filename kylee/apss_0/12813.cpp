/*
**	12813.cpp
**
**	이진수 연산 from acmicpc.net
*/

#include <iostream>
#include <string>

using namespace std;

int		main(void)
{
	string	a;
	string	b;
	bool	aa;
	bool	bb;
	int	i;

	cin >> a >> b;
	i = 0;
	while (i < a.size())
	{
		aa = a.at(i) - '0';
		bb = b.at(i) - '0';
		cout << (aa & bb);
		i++;
	}
	cout << "\n";
	i = 0;
	while (i < a.size())
	{
		aa = a.at(i) - '0';
		bb = b.at(i) - '0';
		cout << (aa | bb);
		i++;
	}
	cout << "\n";
	i = 0;
	while (i < a.size())
	{
		aa = a.at(i) - '0';
		bb = b.at(i) - '0';
		cout << (aa ^ bb);
		i++;
	}
	cout << "\n";
	i = 0;
	while (i < a.size())
	{
		aa = a.at(i) - '0';
		bb = b.at(i) - '0';
		cout << (aa == 0 ? 1 : 0);
		i++;
	}
	cout << "\n";
	i = 0;
	while (i < a.size())
	{
		aa = a.at(i) - '0';
		bb = b.at(i) - '0';
		cout << (bb == 0 ? 1 : 0);
		i++;
	}
	cout << "\n";
}