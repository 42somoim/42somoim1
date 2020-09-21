/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01476.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kylee <kylee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 12:19:39 by kylee             #+#    #+#             */
/*   Updated: 2020/09/14 18:15:26 by kylee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int				main(void)
{
	int			e, e_c;
	int			s, s_c;
	int			m, m_c;
	int			year;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> e >> s >> m;
	e_c = 1;
	s_c = 1;
	m_c = 1;
	year = 1;
	while (1)
	{
		if (e_c == e && s_c == s && m_c == m)
			break ;
		e_c = (e_c >= 15) ? 1 : e_c + 1;
		s_c = (s_c >= 28) ? 1 : s_c + 1;
		m_c = (m_c >= 19) ? 1 : m_c + 1;
		year++;
	}
	cout << year;
}