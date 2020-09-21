#include <iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long a, b;
	cin >> a >> b;
	
	long long result = gcd(a, b);
	
	for (int i = 0; i < result; i++)
		cout << 1;
	cout << "\n";
	
	return 0;
}
