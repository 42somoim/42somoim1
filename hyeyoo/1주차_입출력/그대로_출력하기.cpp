#include <iostream>

using namespace std;

int		main(void)
{
	string line;

	while (getline(cin, line, '\n'))
	{
		cout << line << endl;
	}
	return (0);
}
