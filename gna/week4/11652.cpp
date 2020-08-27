#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<long long> v;
	for (int i = 0; i < N; i++){
		long long val;
		cin >> val;
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	long long card = v[0];
	int cnt = 0, max = 0;
	for (int i = 1; i < N; i++){
		if (v[i] == v[i - 1]) cnt++;
		else cnt = 0;

		if (cnt > max){
			max = cnt;
			card = v[i];
		}
	}
	cout << card << endl;
	return 0;
}
