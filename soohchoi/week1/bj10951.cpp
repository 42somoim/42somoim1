#include <iostream>

int main()
{
	int a, b;
	int n = 5;

	while (std::cin >> a >> b)
	{
		if (a > 0 && a < 10 && b > 0 && b < 10)
			std::cout << a + b << std::endl;
	}
	return 0;
}
