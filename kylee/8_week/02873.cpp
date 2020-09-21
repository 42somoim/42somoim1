/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02873.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 16:05:04 by kylee             #+#    #+#             */
/*   Updated: 2020/09/04 19:53:32 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int list[1005][1005][2];
int main(void)
{
	int r, c, i, j, min, mi, mj;

	cin >> r >> c;
	min = 0x7fffffff;
	i = 0;
	j = 0;
	mi = 0;
	mj = 0;

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 입력 부
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			cin >> list[i][j][0];
			// 홀수 인덱스의 최솟값과 해당 위치를 구한다.
			if ((i + j) % 2 == 1)
			{
				if (min > list[i][j][0])
				{
					min = list[i][j][0];
					mi = i;
					mj = j;
				}
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	// 행이 홀수일 경우
	if (r % 2 == 1)
	{
		while (i < r)
		{
			j = 0;
			while (j < c - 1)
			{
				if (i % 2 == 0)
					cout << "R";
				else
					cout << "L";
				j++;
			}
			if (i == r - 1)
				break ;
			cout << "D";
			i++;
		}
		return (0);
	}
	// 열이 홀수일 경우
	else if (c % 2 == 1)
	{
		while (j < c)
		{
			i = 0;
			while (i < r - 1)
			{
				if (j % 2 == 0)
					cout << "D";
				else
					cout << "U";
				i++;
			}
			if (j == c - 1)
				break ;
			cout << "R";
			j++;
		}
		return (0);
	}
	i = 0;
	j = 0;
	int dir = 0;
	list[mi][mj][1] = 1;

	//반복한다.
	while (1)
	{
		list[i][j][1] = 1;
		if (i == r - 1 && j == c - 1)
			break ;
		// 도착지점일경우 종료
		if (i / 2 == mi / 2)
		{
			//always rightward
			while (1)
			{
				list[i][j][1] = 1;
				if (i % 2 == 0 && i < r - 1 && list[i + 1][j][1] != 1)
				{
					i++;
					j++;
					cout << "DR";
				}
				else if (i % 2 == 1 && i > 0 && list[i - 1][j][1] != 1)
				{
					i--;
					j++;
					cout << "UR";
				}
				else
				{
					j++;
					cout << "R";
				}
				if (j == c - 1)
				{
					if (i == r - 1)
					{
						break ;
					}
					else if (i % 2 == 1 || i == r - 2)
					{
						i++;
						cout << "D";
					}
					else
					{
						i += 2;
						cout << "DD";
					}	
					break ;	
				}
			}
		}
		else
		{
			if (dir == 0 && j != c - 1)
			{
				j++;
				cout << "R";
			}
			else if (dir == 1 && j != 0)
			{
				j--;
				cout << "L";
			}
			if (j == 0 || j == c - 1)
			{
				if (i == r - 1 && j == c - 1)
					break ;
				i++;
				cout << "D";
			}
		}
		if (j == c - 1)
			dir = 1;
		else if (j == 0)
			dir = 0;
	}

}