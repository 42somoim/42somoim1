#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int num1, num2, num3;

	cin >> num1;
	cin >> num2;
	cin >> num3;

	cout << (num1 + num2) % num3 << "\n";
	cout << ((num1 + num3) + (num2 % num3)) % num3 << "\n";
	cout << (num1 * num2) % num3 << "\n";
	cout << ((num1 % num3) * (num2 % num3)) % num3 << "\n";
}