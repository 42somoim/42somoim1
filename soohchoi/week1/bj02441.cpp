#include <iostream>

int main() {
	int N, i, j = 1;

	std::cin >> N;
	while (j <= N)
	{
		for (i = 1; i < j; i++)
			std::cout << " ";
		for (i = 0; i <= N - j; i++)
			std::cout << "*";
	    std::cout << "\n";
	    j++;
	}
	return 0;
}
