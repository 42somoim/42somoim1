#include <iostream>
#include <cstdlib>
using namespace std;

int			main(void)
{
	char		ch;
	int			cnt;

	cnt = 0;
	while(1) {
		ch = cin.get();
		if (ch == '\n')
			break;
		if (cnt != 0 && cnt % 10 == 0)
			cout << endl;
		cout << ch;
		cnt++;
	}
	cout << endl;
	return (0);
}

