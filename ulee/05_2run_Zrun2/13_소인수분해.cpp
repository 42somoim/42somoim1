#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int num;

	cin >> num;
	for (size_t i = 2; num > i; )
	{
		if (num % i == 0)
		{
			cout << i << "\n";
			num /= i;
		}
		else
			i++;
	}
}
