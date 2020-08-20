#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

bool cmp(const pair<long long, int> &a, const pair<long long, int> &b) {
    if (a.second == b.second) return (a.first < b.first);
    return (a.second > b.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
	int N, i;
    long long ans, input;
    map<long long,int> m;
    vector<pair<long long, int>> v;

    cin >> N;

    for(i = 0; i < N; i++) {
        cin >> input;
        m[input]++;
    }

    copy(m.begin(), m.end(), back_inserter(v));

    sort(v.begin(), v.end(), cmp);

    cout << v[0].first;
    return 0;
}