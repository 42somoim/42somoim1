#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>

using namespace std;

class Point {
public:
    int x;
    int y;
    Point(int x, int y) :x(x), y(y) {}
};


bool compare(Point a, Point b) 
{
    if (a.x == b.x) 
    {
        return a.y < b.y;
    }
    else 
    {
        return a.x < b.x;
    }

}

int main(void) 
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int count, x, y;
    vector<Point> v;

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> x;
        cin >> y;
        v.push_back(Point(x, y));
    }

    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < count; i++)
    {
        cout << v[i].x << " " << v[i].y << "\n";
    }
    return 0;
}