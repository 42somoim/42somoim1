/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   좌표_정렬하기.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:07:57 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/08/13 17:29:41 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

using namespace std;

class Person
{
	public:
		int age;
		string name;
		
		Person() { 
		}

		void init(string name, int age) {
			this->age = age;
			this->name = name;
		}
};

bool cmp(Person const &a, Person const &b) {
	return (a.age < b.age);
}

int main(void)
{
	int n;
	Person *person;

	cin >> n;
	person = new Person[n];

	for(int i = 0; i < n; i++) {
		int age;
		string name;;
		cin >> age >> name;
		person[i].init(name, age);
	}
	stable_sort(person, person + n, cmp);

	for(int i = 0; i < n; i++) {
		cout << person[i].age << ' ' << person[i].name << '\n';
	}
	delete[] person;
}
