#include <iostream>
#include <vector>
#include <algorithm>

struct point {
	int x;
	int y;
};

int cmp(point p1, point p2)
{
	if (p1.x > p2.x)
		return 0;
	if (p1.x < p2.x)
		return 1;
	if (p1.y > p2.y)
		return 0;
	if (p1.y < p2.y)
		return 1;
}

int main()
{
	int n;
	std::cin >> n;

	std::vector<point> points;
	for (int i = 0; i < n; i++){
		point p;
		std::cin >> p.x >> p.y;
		points.push_back(p);
	}
	std::sort(points.begin(), points.end(), cmp);
	for (int i = 0; i < n; i++)
		std::cout << points[i].x << ' ' << points[i].y << '\n';
	return 0;
}