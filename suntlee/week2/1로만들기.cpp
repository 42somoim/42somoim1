#include <iostream>

int f(int n)
{
	int a = n > 1 ? n % 3 + f(n/3) + 1 : 0;
	int b = n > 1 ? n % 2 + f(n/2) + 1 : 0;
	return a > b ? b : a;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << f(n);
	return 0;
}	
