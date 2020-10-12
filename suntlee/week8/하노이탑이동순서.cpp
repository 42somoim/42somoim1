#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
		cout << from << " " << to << '\n';
	else
	{
		hanoi(n - 1, from, to, by);
		cout << from << " " << to << '\n';
		hanoi(n - 1, by, from, to);
	}
	
}

int main(int argc, char *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	cout << (int)pow(2, N) - 1 << '\n';
	hanoi(N, 1, 2, 3);
	return 0;
}