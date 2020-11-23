#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

bool check[1000001];

void CheckPrime()
{
	for (int i = 0; i <= 1000000; i++)
	{
		check[i] = true;
	}
	for (int i = 2; i <= sqrt(1000000); i++)
	{
		if (check[i] == false)
		{
			continue;
		}
		for (int t = i * 2; t <= 1000000; t += i)
		{
			check[t] = false;
		}
	}
}



int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	int num;
	cin >> num;
	for (int i = 2; i <= num; i++)
	{
		if (num % i == 0)
		{
			while (num % i == 0)
			{
				cout << i << "\n";
				num /= i;
				if (num == 0)
					break;
			}

		}
	}
	return 0;
}