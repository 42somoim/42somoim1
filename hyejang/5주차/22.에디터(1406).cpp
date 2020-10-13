#include<iostream>
#include<algorithm>
#include<list>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count;
	char command, ch;
	string str;
	list<char> lst;
	list<char>::iterator cursor = lst.end();

	cin >> str;
	cin >> count;
	for (int i = 0; i < str.length(); i++)
	{
		lst.push_back(str[i]);
	}
	for (int i = 0; i < count; i++)
	{
		cin >> command;
		if (command == 'L')
		{
			if (cursor != lst.begin())
			{
				cursor--;
			}
		}
		else if (command == 'D')
		{
			if (cursor != lst.end())
			{
				 cursor++;
			}
		}
		else if (command == 'B')
		{
			if (cursor != lst.begin())
			{
				cursor = lst.erase(--cursor);
			}
		}
		else if (command == 'P')
		{
			cin >> ch;

			lst.insert(cursor, ch);
		}
	}
	for (cursor = lst.begin(); cursor != lst.end(); ++cursor) 
	{
		cout << *cursor;
	}
}