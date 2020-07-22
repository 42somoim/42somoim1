#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	for (int i = n; i > 0; --i) {
		for (int j = 0; j < i; j++)
			std::cout << '*';
		std::cout << '\n';
	}
	return 0;
}
