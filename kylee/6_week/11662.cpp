/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11662.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 22:53:07 by kylee             #+#    #+#             */
/*   Updated: 2020/08/20 00:29:26 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

using namespace std;

double sq(double x)
{
	return (x * x);
}
double len(double x1, double y1, double x2, double y2)
{
	return (sqrt(sq(x1 - x2) + sq(y1 - y2)));
}

int	comp(double a, double b, double c)
{
	if (a > b && a > c)
		return (b > c ? 3 : 2);
	else if (b > a && b > c)
		return (a > c ? 3 : 1);
	return (a > b ? 2 : 1);
}

int main(void)
{
	double ax, ay, bx, by, cx, cy, dx, dy;
	double lo = 0, hi = 1, mid;
	cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
	while (hi - lo >= 1e-10)
	{
		mid = (lo + hi) / 2;
		//cout << lo << " " << mid << " " << hi << "\n";
		double x1, y1, x2, y2;
		x1 = ((bx * mid) + (1 - mid) * ax);
		y1 = ((by * mid) + (1 - mid) * ay);
		x2 = ((dx * mid) + (1 - mid) * cx);
		y2 = ((dy * mid) + (1 - mid) * cy);
		int temp;

		temp = comp(len(ax, ay, cx, cy), len(x1, y1, x2, y2), len(bx, by, dx, dy));
		if (temp == 1)
		{
			bx = x1;
			by = y1;
			dx = x2;
			dy = y2;
			hi = mid;
		}
		else if (temp == 3)
		{
			ax = x1;
			ay = y1;
			cx = x2;
			cy = y2;
			lo = mid;
		}
		else if (temp == 2)
		{
			ax = (ax + x1) / 2;
			ay = (ay + y1) / 2;
			bx = (bx + x1) / 2;
			by = (by + y1) / 2;
			cx = (cx + x2) / 2;
			cy = (cy + y2) / 2;
			dx = (dx + x2) / 2;
			dy = (dy + y2) / 2;
			lo += 1e-10;
			hi -= 1e-10;
		}
	}
	cout.precision(11);
	cout << len(ax, ay, cx, cy);
}