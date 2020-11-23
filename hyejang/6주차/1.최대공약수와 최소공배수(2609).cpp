#include <iostream>
#include <vector>

using namespace std;

int one(int num1, int num2)
{
	int tmp = num1;
	for (; tmp > 0; tmp--)
	{
		if (num1 % tmp == 0 && num2 % tmp == 0)
		{
			cout << tmp << "\n";
			break;
		}
	}
	return tmp;
}

void two(int num1, int num2)
{
	cout << num1 * (num2 / one(num1, num2)) << "\n";
}

int main() 
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num1, num2;

	cin >> num1;
	cin >> num2;
	two(min(num1, num2), max(num1, num2));
}