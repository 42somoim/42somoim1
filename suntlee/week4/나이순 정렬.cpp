#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct member {
	int age;
	string name;
};

int cmp(member m1, member m2)
{
	return (m1.age < m2.age);
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
		cin >> m.age >> m.name;
		members.push_back(m);
	}
	stable_sort(members.begin(), members.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << members[i].age << ' ' << members[i].name << '\n';
	return 0;
}