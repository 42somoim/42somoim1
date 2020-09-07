#include <iostream>

int main()
{
	int t;
	int a, b;

	std::cin >> t;

	while (t > 0)
	{
		std::cin >> a;
		std::cin >> b;
		std::cout << a + b << std::endl;
		t--;
	}
	return 0;
}
