#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count, value;
	queue<int> que;
	string command;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> command;
		if (command == "push")
		{
			cin >> value;
			que.push(value);
		}
		else if (command == "pop")
		{
			if (que.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.front() << "\n";
				que.pop();
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