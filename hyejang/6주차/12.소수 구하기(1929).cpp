#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool value[1000001] = { true };

void isPrime(int num, int num2)
{
	value[1] = true;
	for (int i = 2; i <= num; i++)
	{
		if (value[i] == true)
		{
			continue;
		}

		for (int t = i * 2 ; t <= num; t += i)
		{
			value[t] = true;
		}
	}
	for (int j = num2; j <= num; j++)
	{
		if (value[j] == false)
		{
			cout << j << "\n";
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, num2;

	cin >> num;
	cin >> num2;
	isPrime(num2, num);
}