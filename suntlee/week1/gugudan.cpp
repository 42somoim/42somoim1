#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i < 10; i++) {
		std::cout << n << " * " << i << " = " << n * i << '\n';
	}
	return 0;
}
