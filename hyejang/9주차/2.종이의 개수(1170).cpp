#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int result[3];
int arr[2188][2188];

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
		result[arr[row][column]]++;
	}
	else
	{
		int re_size = size / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Divid(row + (re_size * i), column + (re_size * j), re_size);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int size;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> arr[i][j];
			arr[i][j]++;
		}
	}

	Divid(0, 0, size);
	for (int i = 0; i < 3; i++)
	{
		cout << result[i] << "\n";
	}
	return 0;
}