#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

	int arr[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	int time = 0;
	int tmp = 0;
	for (int i = 0; i < N; i++){
		tmp += arr[i];
		time += tmp;
	}
	cout << time;
	return 0;
}