#include <iostream>

int main() {
	int i, sum = 0;

	std::cin >> i;
	while (i > 0)
	{
		sum += i;
		i--;
	}
	std::cout << sum << "\n";
	return 0;
}
