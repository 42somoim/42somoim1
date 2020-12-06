#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 6;
int k;
int lotto[MAX];
int arr[13];
 
void printLotto(int idx1, int cnt)
{
	if (cnt == MAX)
	{
		for (int i = 0; i < MAX; i++)
			cout << lotto[i] << " ";
		cout << endl;
		return;
	}

	for (int i = idx1; i < k; i++)
	{
		lotto[cnt] = arr[i];
		printLotto(i + 1, cnt + 1);
	}

}

 

int main(void)
{

	while (1)
	{
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
			cin >> arr[i];
		printLotto(0, 0);
		cout << endl;
	}
	return 0;
}
