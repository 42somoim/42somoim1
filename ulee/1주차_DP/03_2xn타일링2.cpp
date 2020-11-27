#include <iostream>

using namespace std;
int main()
{
	int n;
	int result[1000];

	cin >> n;
	result[1] = 1;
	result[2] = 3;
	for (int i = 3; i <= n; i++)
		result[i] = ((result[i - 2] * 2) + result[i - 1]) % 10007;
	cout << result[n] % 10007;
}
