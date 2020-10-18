#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int count[10001] = { 0 };
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		count[num]++;
	}

	for (int i = 1; i <= 10000; i++) 
	{
		while (count[i]--)
			cout << i << '\n';
	}
}