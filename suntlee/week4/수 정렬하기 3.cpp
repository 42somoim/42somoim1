#include <iostream>

using namespace std;

int arr[10001] = {0, };
int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int N, temp, max;

    cin >> N;

    max = 0;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        arr[temp]++;
        if (temp > max) max = temp;
    }

    for (int i = 0; i <= max; i++) {
        for(int j = 0; j < arr[i]; j++)
			cout << i << '\n';
    }
    return 0;
}