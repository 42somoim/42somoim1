#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	int result[1000000];
	int n;

	cin >> n;
	result[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		result[i] = result[i - 1] + 1;
		if (i % 2 == 0)
			result[i] = min(result[i], result[i / 2] + 1);
		if (i % 3 == 0)
			result[i] = min(result[i], result[i / 3] + 1);
	}

	cout << result[n];
	return (0);
}