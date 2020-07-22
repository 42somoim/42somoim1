#include <iostream>
#include <string>

int main()
{
	int n;
	std::string line;
	int sum = 0;
	std::cin >> n;
	std::cin.ignore(256, '\n');
	std::getline(std::cin, line);
	while (n--)
		sum += line[n] - 48;
	std::cout << sum;
	return 0;
}
