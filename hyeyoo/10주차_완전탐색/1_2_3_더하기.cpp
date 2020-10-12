#include <iostream>

using namespace std;

int amount(int N) {
	if (N == 0)
		return 1;
	else {
		int ret = 0;
		if (N - 1 >= 0)
			ret += amount(N - 1);
		if (N - 2 >= 0)
			ret += amount(N - 2);
		if (N - 3 >= 0)
			ret += amount(N - 3);
		return ret;
	}
}

int		main(void)
{
	int T;
	
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << amount(N) << endl;
	}
	return 0;
}
