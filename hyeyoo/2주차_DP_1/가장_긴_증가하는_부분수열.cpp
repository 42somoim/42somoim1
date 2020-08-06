#include <iostream>
#include <vector>

using namespace std;

int	main(void)
{
	int n;
	int num;
	vector<int> v;
	vector<int> d;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		d.push_back(1);
		for(int j = 0; j < i; j++)
		{
			if (v[i] > v[j])
				d[i] = max(d[i], d[j] + 1);
		}
		ans = max(ans, d[i]);
	}
	cout << ans << endl;
}

