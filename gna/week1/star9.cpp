#include <iostream>
using namespace std;
 
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int N;
	cin >> N;
 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++)
			cout << ' ';
		for (int j = 1; j <= (2 * (N - i)) - 1; j++)
			cout << '*';
		cout << '\n';
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N - i; j++)
			cout << ' ';
		for (int j = 1; j <= (2 * i) + 1; j++)
			cout << '*';
		cout << '\n';
	}
 
	return 0;
}
