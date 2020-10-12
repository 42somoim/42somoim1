#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count, value;
	deque<int> que;
	string command;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> command;
		if (command == "push_front")
		{
			cin >> value;
			que.push_front(value);
		}
		else if (command == "push_back")
		{
			cin >> value;
			que.push_back(value);
		}
		else if (command == "pop_front")
		{
			if (que.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.front() << "\n";
				que.pop_front();
			}
		}
		else if (command == "pop_back")
		{
			if (que.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.back() << "\n";
				que.pop_back();
			}
		}
		else if (command == "size")
		{
			cout << que.size() << "\n";
		}
		else if (command == "empty")
		{
			cout << que.empty() << "\n";
		}
		else if (command == "front")
		{
			if (que.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.front() << "\n";
			}
		}
		else if (command == "back")
		{
			if (que.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.back() << "\n";
			}
		}
	}
}