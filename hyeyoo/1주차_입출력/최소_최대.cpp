#include <iostream>

using namespace std;

int		main(void)
{
	int n, ans_min, ans_max, num;

	cin >> n;
	ans_max = 1;
	ans_min = 1000000;

	while (n--)
	{
		cin >> num;
		ans_max = max(ans_max, num);
		ans_min = min(ans_min, num);
	}
	cout << ans_min << " " << ans_max << endl;
}
