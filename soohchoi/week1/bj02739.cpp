#include <iostream>

int main() {
	int N, i = 1;

	std::cin >> N;
	while (i <= 9)
	{
		std::cout << N << " * " << i << " = " << N * i << "\n";
	    i++;
	}
	return 0;
}
