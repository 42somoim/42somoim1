#include <iostream>
#include <vector>

using namespace std;

void one(long long num1, long long num2)
{
	long long tmp;
	while (num1 != 0)
	{
		tmp = num2 % num1;
		num2 = num1;
		num1 = tmp;
	}
	for (long long i = 0; i < num2; i++)
	{
		cout << "1";
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	long long num1, num2;

	cin >> num1;
	cin >> num2;
	one(min(num1, num2), max(num1, num2));
}