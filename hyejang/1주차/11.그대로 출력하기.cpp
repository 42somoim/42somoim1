#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;

	while (1)
	{
		getline(cin, str);
		if (cin.eof())
			return (0);
		cout << str << "\n";
	}
}