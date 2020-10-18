#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int alpha[26] = { 0 };
	string command;

	cin >> command;
	for (int i = 0; i < command.length(); i++)
	{
		if (alpha[command[i] - 97] == 0)
		{
			alpha[command[i] - 97] = i + 1;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		alpha[i]--;
		cout << alpha[i] << " ";
	}
}