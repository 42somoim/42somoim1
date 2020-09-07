#include <iostream>

int main()
{
	int a, b;
	int n = 5;

	while (1)
	{
		std::cin >> a >> b;
		if (a == 0 && b == 0)
			return 0;
		if (a > 0 && a < 10 && b > 0 && b < 10)
			std::cout << a + b << std::endl;
	}
	return 0;
}
