#include <iostream>
#include <vector>
using namespace std;
int N, K;
vector<int> v;
vector<int> res;

int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++) v.push_back(i);
	int idx = K - 1;

	while (!v.empty()) {
		res.push_back(v[idx]);
		v.erase(v.begin() + idx);
		idx += K-1;
		while (idx >= v.size() && !v.empty())
			idx -= v.size();
	}

	cout << "<" << res[0];
	for (int i = 1; i < res.size(); i++)
		cout << ", " << res[i];
	cout << ">";
}
