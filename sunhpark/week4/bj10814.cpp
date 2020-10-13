#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool		compare(pair<int, string> a, pair<int, string> b)
{
    return (a.first < b.first);
}

int			main(void)
{
	int		N;
	vector <pair <int, string>> user;
	pair<int, string> tmp;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp.first >> tmp.second;
		user.push_back(tmp);
	}
	stable_sort(user.begin(), user.end(), compare);
	for (int i = 0; i < N; i++)
	{
		cout << user[i].first << ' ' << user[i].second << '\n';
	}
	return (0);
}
