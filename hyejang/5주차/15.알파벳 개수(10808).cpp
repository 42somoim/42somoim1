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
		alpha[command[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << alpha[i] << " ";
	}
}