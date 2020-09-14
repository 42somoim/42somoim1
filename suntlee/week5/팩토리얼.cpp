#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N, result;
	cin >> N;
	
	result = 1;
	while (N)
		result *= N--;
	cout << result;
	return 0;
}