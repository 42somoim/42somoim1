#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct member {
	string name;
    int korean;
    int english;
    int math;
};

int cmp(member m1, member m2)
{
	if (m1.korean == m2.korean){
        if (m1.english == m2.english)
            return (m1.math == m2.math) ? m1.name < m2.name : m1.math > m2.math;
        return m1.english < m2.english;
    }
    return m1.korean > m2.korean; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<member> members;
	member m;
	for (int i = 0; i < n; i++){
		cin >> m.name >> m.korean >> m.english >> m.math;
		members.push_back(m);
	}
	stable_sort(members.begin(), members.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << members[i].name << '\n';
	return 0;
}