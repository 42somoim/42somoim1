#include <iostream>

int main() {
	int N, i;

	std::cin >> N;
	while (N > 0)
	{
		for (i = N; i > 0; i--)
			std::cout << "*";
		std::cout << "\n";
		N--;
	}
	return 0;
}
