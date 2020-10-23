#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting {
	int start;
	int end;
}; 

bool cmp(meeting a, meeting b)
{
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}

void print(meeting m)
{
	cout << "Start: " << m.start << ", " << "End: " << m.end << '\n';
}

int main(void) 
{
	int N;
	cin >> N;

	vector<meeting> m(N);

	for (int i = 0; i < N; ++i)
		cin >> m[i].start >> m[i].end;
	sort(m.begin(), m.end(), cmp);
	// for_each(m.begin(), m.end(), print);

	int cnt = 0;
	int end = 0;

	for (int i = 0; i < N; ++i) {
		if (end <= m[i].start){
			end = m[i].end;
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}