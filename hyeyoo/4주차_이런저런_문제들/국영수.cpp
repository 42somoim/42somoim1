/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   좌표_정렬하기.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:07:57 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 17:50:30 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

class Person
{
	public:
		int korean;
		int english;
		int math;
		string name;
		
		Person() { 
		}

		void init(int korean, int english, int math, string name) {
			this->korean = korean;
			this->english = english;
			this->math = math;
			this->name = name;
		}
};

bool cmp(Person const &a, Person const &b) {
	if (a.korean == b.korean) {
		if (a.english == b.english) {
			if (a.math == b.math) {
				return (a.name < b.name);
			} else {
				return (a.math > b.math);
			}
		} else {
			return (a.english < b.english);
		}
	} else {
		return (a.korean > b.korean);
	}
}

int main(void)
{
	int n;
	Person *person;

	cin >> n;
	person = new Person[n];

	for(int i = 0; i < n; i++) {
		int korean, english, math;
		string name;;
		cin >> name >> korean >> english >> math;
		person[i].init(korean, english, math, name);
	}
	sort(person, person + n, cmp);

	for(int i = 0; i < n; i++) {
		cout << person[i].name << '\n';
	}
	delete[] person;
}
