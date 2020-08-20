#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin>> n >> k;

	vector<int> vec;
	for (int i = 1; i <= n; i++)
		vec.push_back(i);

	int cur = -1;
	int max = n;

	cout << "<";
	for (int i = 0; i < n; i++)
	{
		cur = (cur + k) % max;

		cout << vec[cur];
		vec.erase(vec.begin() + cur);
		cur--;
		max--;

		if (i == n-1)
			cout << ">\n";
		else
			cout << ", ";
	}
	return 0;
}