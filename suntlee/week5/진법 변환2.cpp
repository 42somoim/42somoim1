#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, b;
	cin >> n >> b;

	vector<int> v;

	while (1)
	{
		v.push_back(n % b);
		n /= b;
		if (n == 0)
			break;
	}

	for (auto iter = v.rbegin(); iter != v.rend(); iter++)
	{
		if (*iter >= 10)
			cout << (char)(*iter - 10 + 'A');
		else
			cout << *iter;		
	}
	return 0;
}