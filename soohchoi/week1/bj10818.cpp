#include <iostream>

int main() {
	int N;
	int temp;
	int min, max;

	std::cin >> N;
	std::cin >> temp;
	min = temp;
	max = temp;
	while (N > 1)
	{
		std::cin >> temp;
		if (temp > max)
			max = temp;
		if (temp < min)
			min = temp;
		N--;
	}
	std::cout << min << " " << max << "\n";
    return 0;
}
