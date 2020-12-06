#include <iostream>

using namespace std;
int main()
{
	int n;
	int result[11];

	cin >> n;
	result[1] = 1;
	result[2] = 2;
	result[3] = 4;
	for (int i = 4; i <= n; i++)
	{
		result[i] = result[i - 3] + result[i - 2] + result[i - 1];
	}
	cout << result[n];
}
