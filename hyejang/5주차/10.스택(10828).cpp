#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count, value;
	stack<int> stk;
	string command;

	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> command;
		if (command == "push")
		{
			cin >> value;
			stk.push(value);
		}
		else if (command == "pop")
		{
			if (stk.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << stk.top() << "\n";
				stk.pop();
			}
		}
		else if (command == "size")
		{
			cout << stk.size() << "\n";
		}
		else if (command == "empty")
		{
			cout << stk.empty() << "\n";
		}
		else if (command == "top")
		{
			if (stk.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << stk.top() << "\n";
			}
		}
	}
}