#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
		cout << from << " " << to << "\n";
	else
	{
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << "\n";
		hanoi(n - 1, by, from, to);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int size;

	cin >> size;
	cout << ((int)pow(2, size) - 1) << "\n";
	hanoi(size, 1, 2, 3);
	
	return 0;
}