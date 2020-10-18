#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int				N;

struct			Student
{
	int			kor, eng, math;
	string		name;
};

bool			compare(Student &a, Student &b)
{
	if (a.kor != b.kor)
		return (a.kor > b.kor);
	else if (a.eng != b.eng)
		return (a.eng < b.eng);
	else if (a.math != b.math)
		return (a.math > b.math);
	else if (a.name.compare(b.name) < 0)
		return true;
	else
		return false;
}

int				main(void)
{
	cin >> N;
	vector<Student> student;
	Student			tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp.name >> tmp.kor >> tmp.eng >> tmp.math;
		student.push_back(tmp);
	}
	sort(student.begin(), student.end(), compare);
	for (int i = 0; i < N; i++)
	{
		cout << student[i].name << '\n';
	}
	return (0);
}

