#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return (a.first < b.first);
    else
        return (a.second < b.second);
}

int main()
{
    int N;
    int x, y;
    vector<pair<int,int> > v;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < N; i++)
        cout << v[i].first << " " << v[i].second << "\n";
    return (0);
}