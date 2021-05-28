#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX = 1000000;

int	is_prime(int input)
{
	for (size_t i = 2; i <= sqrt(input); i++)
	{
		if (input % i == 0)	return (0);
	}
	return (1);
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int num = 1;
	int a,b;
	int flag;

	flag = 0;
	while (num)
	{
		cin >> num;
		for (size_t i = 1; i < num / 2; i++)
		{
			a = i * 2 + 1;
			b = num - a;
			if (is_prime(a) && is_prime(b))
			{
				cout << num << " = " << a << " + " << b << "\n";
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "Goldbach's conjecture is wrong\n";
	}
}
