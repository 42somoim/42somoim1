#include <iostream>

int main() {
	int N, j = 1, i;

	std::cin >> N;
	while (j <= N)
	{
		for (i = 0; i < j; i++)
			std::cout << "*";
		std::cout << "\n";
		j++;
	}
	return 0;
}
