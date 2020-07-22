#include <iostream>

int main()
{
	int a, b, n;
	char c;
	std::cin >> n;
	for (int i = 0; i < n; i++){
		std::cin >> a >> c >> b;
		std::cout << a + b << std::endl;
	}
	return 0;
}
