#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num, count = 0;

	cin >> num;
	if (num == 0)
	{
		cout << "0" << "\n";
		return 0;
	}
	for (int i = 2; i <= num; i++) 
	{
		if (i % 5 == 0) 
		{
			count++;
		}
		if (i % 25 == 0)
		{
			count++;
		}
		if (i % 125 == 0)
		{
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}