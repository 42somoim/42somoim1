#include <iostream>

int main()
{
	int t;
	int i = 1;
	int a, b;

	std::cin >> t;
	while (i <= t)
	{
		std::cin >> a >> b;
		if (a > 0 && a < 10 && b > 0 && b < 10)
			std::cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << std::endl;
		i++;
	}
	return 0;
}
