#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 1000;
const int INF = 2147483647;

int arr[MAX][MAX];
string result;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int R, C;
	cin >> R >> C;

	if (R % 2)
	{
		for (int y = 0; y < R; ++y)
		{
			for (int x = 0; x < C - 1; ++x)
			{
				if ((y % 2) == 0)
					result += "R";
				else
					result += "L";				
			}
			if (y != R - 1)
				result += "D";
		}
	}
	else if (!(R % 2) && (C % 2))
	{
		for (int x = 0; x < C; ++x)
		{
			for (int y = 0; y < R - 1; ++y)
			{
				if ((x % 2) == 0)
					result += "D";
				else
					result += "U";
			}
			if (x != C - 1)
				result += "R";
		}
	}
	else
	{
		pair<int, int> minSpot;
		int minScore = INF;
		for (int y = 0; y < R; ++y)
		{
			for (int x = 0; x < C; ++x)
			{
				cin >> arr[y][x];
				if (((y + x) % 2) && (minScore > arr[y][x]))
				{
					minSpot = {y, x};
					minScore = arr[y][x];
				}
			}
		}
		int newR = minSpot.first % 2 ? minSpot.first - 1 : minSpot.first;
		for (int y = 0; y < newR; y++)
		{
			for (int x = 0; x < C - 1; x++)
				if (y % 2 == 0)
					result += 'R';
				else
					result += 'L';
			result += 'D';
		}

		int newC = minSpot.second;
		for (int x = 0; x < newC; ++x)
		{
			if (x % 2)
				result += "UR";
			else
				result += "DR";
		}
		for (int x = newC; x < C - 1; ++x)
		{
			if (x % 2)
				result += "RU";
			else
				result += "RD";
		}
		newR = minSpot.first % 2 ? R - minSpot.first - 1 : R - minSpot.first - 2;
		for (int y = 0; y < newR; ++y)
		{
			result += "D";
			for (int x = 0; x < C - 1; ++x)
			{
				if (y % 2)
					result += "R";
				else
					result += "L";
			}
		}
	}
	cout << result;
	return 0;
}