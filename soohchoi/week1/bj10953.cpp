#include <iostream>

int main()
{
	int t;
	int a, b;
	char c;

	std::cin >> t;
	while (t > 0)
	{
		std::cin >> a >> c >> b;
		if (a > 0 && a < 10 && b > 0 && b < 10)
			std::cout << a + b << std::endl;
		t--;
	}
	return 0;
}
