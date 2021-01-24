#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arr[65][65];

bool check(int start_row, int start_column, int size)
{
	int start = arr[start_row][start_column];

	for (int i = start_row; i < start_row + size; i++)
	{
		for (int j = start_column; j < start_column + size; j++)
		{
			if (start != arr[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

//처음에 총 9번의 실행
void Divid(int row, int column, int size)
{
	if (check(row, column, size))
	{
		cout << arr[row][column];
	}
	else
	{
		cout << "(";
		int re_size = size / 2;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				Divid(row + (re_size * i), column + (re_size * j), re_size);
			}
		}
		cout << ")";
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int size;
	string tmp;

	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> tmp;
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = tmp[j] - 48;
		}
	}
	Divid(0, 0, size);

	return 0;
}
/*

8
00001111
00001111
00000011
00000011
11110001
11111111
11111111
11111110
*/