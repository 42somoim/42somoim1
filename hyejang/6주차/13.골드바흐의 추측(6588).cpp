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

	int num = 1;
	CheckPrime();
	while (num != 0)
	{
		cin >> num;
		if (num == 0)
		{
			return (0);
		}
		else if (num < 6 || num % 2 == 1 || num > 10000001)
		{
			cout << "Goldbach's conjecture is wrong." << "\n";
		}
		else
		{
			for (int i = 3; i <= num - 3; i++)
			{
				if (check[i] == true && check[num - i] == true)
				{
					cout << num << " = " << i << " + " << num - i << "\n";
					break;
				}		
			}
		}
	}
	return 0;
}