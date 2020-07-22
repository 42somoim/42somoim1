#include <iostream>

int main()
{
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);
	int a, b, n;
	std::cin >> n;
	while (n--){
		std::cin >> a >> b;
		std::cout << a + b << "\n";
	}
	return 0;
}
