#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string str;

	while (getline(cin, str))
	{
		int count[4] = { 0 };

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z') 
			{
				count[0] += 1;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				count[1] += 1;
			}
			else if (str[i] >= '0' && str[i] <= '9')
			{
				count[2] += 1;
			}
			else if (str[i] == ' ')
			{
				count[3] += 1;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			cout << count[i] << " ";
		}
		cout << "\n";
	}
}