#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
	int x, y;
};

bool	compare(const Point &a, const Point &b)
{
	if (a.x < b.x) return true;
	else if (a.x == b.x)
		return a.y < b.y;
	else
		return false;
}

int		main(void)
{
	int		N;
	scanf("%d", &N);
	vector<Point> v;
	Point p;
	int		a, b;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		p.x = a;
		p.y = b;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", v[i].x, v[i].y);
	}
	return (0);
}

