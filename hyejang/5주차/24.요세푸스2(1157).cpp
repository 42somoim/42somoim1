#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int people, count, max, cur = -1;
	vector<int> vec;

	cin >> people;
	cin >> count;
	max = people;

	for (int i = 0; i < people; i++)
	{
		vec.push_back(i + 1);
	}
	cout << "<";
	for (int i = 0; i < people; i++) 
	{
		cur = (cur + count) % max;
		cout << vec[cur];
		//vec.erase(vec.begin() + cur);
		cur--; 
		max--;

		if (i == people - 1)
		{
			cout << ">\n";
		}
		else
		{
			cout << ", ";
		}
	}
}