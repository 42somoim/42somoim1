#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool value[10001] = { true };

int isPrime(int num)
{

	if (num <= 1)
	{
		return 0;
	}
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

	if (value[num] == false)
	{
		return 1;
	}
	
	return 0;

}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count, num, result = 0;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> num;
		result += isPrime(num);
	}
	cout << result << "\n";
}