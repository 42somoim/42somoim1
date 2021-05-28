#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string v;

	cin >> n;
	if (n == 0)
		v += "0";
	while (n)
	{
		if (n % -2 == 0)
		{
			v += "0"; n /= -2;
		}
		else
		{
			v += "1"; n = (n - 1) / -2;
		}
	}
	reverse(v.begin(), v.end());
	cout << v << "\n";
}
