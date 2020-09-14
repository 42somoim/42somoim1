#include <iostream>
#include <string>

using namespace std;

long long n;

void find(long long a) {

	if (a == 1) 
	{
		cout << 1;
		return;
	}

	if (a < 0 && a % -2 == -1)
    {
		a /= -2;
		a += 1;
		find(a);
		cout << 1;
	}
	else
    { 
		long long temp = a % -2;
		a /= -2;
		find(a);
		cout << temp;
    }
}

int main()
{

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;

	if (n == 0)
    {
		cout << 0 << '\n';
		return 0;
	}

	find(n);

	cout << '\n';

	return 0;
}