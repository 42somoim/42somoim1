#include<algorithm>
#include<string>
#include<iostream>
#include <sstream>

using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string num1, num2, num3, num4;
	long long result1, result2, result3;

	cin >> num1 >> num2 >> num3 >> num4;
	string tmp = num1 + num2;
	string tmp1 = num3 + num4;
	std::stringstream ssInt1(tmp);
	std::stringstream ssInt2(tmp1);

	ssInt1 >> result1;
	ssInt2 >> result2;
	result3 = result1 + result2;
	cout << result3 << "\n";
}