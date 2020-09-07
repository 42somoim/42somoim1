#include <iostream>
#include <string>

int main() {
	std::string str;
	int i = 0;

	while (std::getline(std::cin, str) && i < 100)
	{
		std::cout << str << "\n";
		i++;
	}
	return 0;
}
