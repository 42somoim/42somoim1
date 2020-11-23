#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int fucture_base, current_base, count, num, result = 0;
	vector<int> vec;

	cin >> fucture_base;
	cin >> current_base;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> num;
		result = (fucture_base * result + num);
	}
	while (result != 0) 
	{
		vec.push_back(result % current_base);
		result = result / current_base;
	}
	for (int i = vec.size() - 1; i >= 0; i--) 
	{
		cout << vec[i];
		if (i != 0)
		{
			cout << " ";
		}
	}
}