#include <iostream>

using namespace std;
int main()
{
	int n;
	int result[1000];

	cin >> n;
	result[1] = 1;
	result[2] = 2;
	for (int i = 3; i <= n; i++)
		result[i] = (result[i - 1] + result[i - 2]) % 10007;
	cout << result[n] % 10007;
}
