#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	deque<int> deq;
	string str;
	
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "push_back")
		{
			int num;
			cin >> num;
			deq.push_back(num);
		}
		else if (str == "push_front")
		{
			int num;
			cin >> num;
			deq.push_front(num);
		}
		else if (str == "pop_front")
		{
			if (!deq.empty())
			{
				cout << deq.front() << '\n';
				deq.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (str == "pop_back")
		{
			if (!deq.empty())
			{
				cout << deq.back() << '\n';
				deq.pop_back();
			}
			else
				cout << "-1\n";
		}
		else if (str == "size")
			cout << deq.size() << '\n';
		else if (str == "empty")
			cout << (deq.empty() ? 1 : 0) << '\n';
		else if (str == "front")
		{
			if (!deq.empty())
				cout << deq.front() << '\n';
			else
				cout << "-1\n";
		}
		else if (str == "back")
		{
			if (!deq.empty())
				cout << deq.back() << '\n';
			else
				cout << "-1\n";
		}
	}
	return 0;
}