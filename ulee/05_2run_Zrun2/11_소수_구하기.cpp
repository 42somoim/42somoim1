#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int min, max;
	bool *prime;

	cin >> min >> max;

	prime = new bool[max + 1];
	fill_n(prime, max + 1, 1);

	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(max); i++)
	{
		if (prime[i] == true)
		{
			for (int j = i * i; j <= max; j += i)
			{
				prime[j] = false;
			}
		}
	}
	for (int i = min; i <= max; i++)
	{
		if (prime[i] == true)
			cout << i << "\n";
	}
	return (0);
}
