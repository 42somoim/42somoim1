#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int input;
	int count;

	cin >> input;
	count = input / 5 + input / 25 + input / 125;
	cout << count << "\n";
}
