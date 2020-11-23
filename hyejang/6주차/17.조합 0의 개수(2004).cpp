#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int CountValue(int num, int value)
{
	int count = 0;

	for (long long i = value; num / i >= 1; i *= value)
	{
		count += num / i;
	}

	return count;
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, m, two_count = 0, five_count = 0;

	cin >> n;
	cin >> m;

	two_count += CountValue(n, 2);
	two_count -= CountValue(n - m, 2);
	two_count -= CountValue(m, 2);

	five_count += CountValue(n, 5);	
	five_count -= CountValue(n - m, 5);
	five_count -= CountValue(m, 5);

	cout << min(two_count, five_count) << "\n";
	return 0;
}