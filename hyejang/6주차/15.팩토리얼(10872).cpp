#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int factorial(int num)
{
	if (num <= 1)
	{
		return 1;
	}

	return num * factorial(num - 1);
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int num, result = 0;

	cin >> num;
	result = factorial(num);
	cout << result << "\n";
	return 0;
}