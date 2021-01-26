#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

char map[1024 * 3 + 1][1024 * 6 + 1];

void star(int i, int j, int num)
{
	if (num == 3)
	{
		map[i][j + 2] = '*';
		map[i + 1][j + 1] = '*';
		map[i + 1][j + 3] = '*';
		for (int k = 0; k < 5; k++)
		{
			map[i + 2][j + k] = '*';
		}
		return;
	}
	star(i, j + num / 2, num / 2);
	for (int k = 0; k < 3; k++) 
	{
		if (k == 1)
		{
			continue;
		}
		star(i + num / 2, j + k * (num / 2), num / 2);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num * 2; j++)
		{
			map[i][j] = ' ';
		}
	}
	star(0, 0, num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num * 2 - 1; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
	return 0;
}
/*
* 	 
  *
 * *
*****

     *
    * *
   *****
  *     *
 * *   * *
***** *****


           *
		  * *
		 *****
		*     *
	   * *   * *
	  ***** *****
	 *           *
	* *         * *
   *****       *****
  *     *     *     *
 * *   * *   * *   * *
***** ***** ***** *****
*/