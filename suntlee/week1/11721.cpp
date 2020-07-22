#include <iostream>
#include <string>

int main()
{
	std::string line;
	std::getline(std::cin, line);
	int len = line.length();
	for (int n = 0; n < len; n += 10){
		for (int i = 0; i < 10 && n + i < len; i++)
			std::cout << line[n + i];
		std::cout << '\n';
	}
	return 0;
}
