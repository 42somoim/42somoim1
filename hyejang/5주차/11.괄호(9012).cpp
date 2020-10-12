#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count, value = 0;
	stack<int> stk;
	string command;
	
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		value = 0;
		cin >> command;
		if (command[0] == ')' || command[command.size() - 1] == '(')
		{
			cout << "NO" << "\n";
			continue ;
		}
		for (int j = 0; j < command.length(); j++)
		{
			if (command[j] == '(')
			{
				stk.push(1);
			}
			else
			{
				if (stk.empty() == 1)
				{
					value = 1;
					break ;
				}
				else
				{
					stk.pop();
				}
			}
		}
		if (stk.empty() == 1 && value == 0)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
			while (stk.empty() != 1)
			{
				stk.pop();
			}
		}
	}
}