#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num, base;
	string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string result;

	cin >> num;
	cin >> base;
	while (num != 0)
	{
		result += alphabet[num % base];
		num /= base;
	}
	for (int i = result.length() - 1; i >= 0 ; i--)
	{
		cout << result[i];
	}
}