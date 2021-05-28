#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int input;
	int	num;

	cin >> input;
	num = 1;
	for (size_t i = 1; i <= input; i++)
	{
		num *= i;
	}
	cout << num << "\n";
}
