#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> positive;
priority_queue<int> negative;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	int one = 0, zero = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (num == 1)
			one++;
		else if (num > 0)
			positive.push(num);
		else if (num == 0)
			zero++;
		else
			negative.push(num);
	}
	if (positive.size() % 2)
		positive.push(1);
	if (negative.size() % 2)
		zero == 0 ? negative.push(1) : negative.push(0);
	int sum = 0;
	while(!positive.empty())
	{
		int num1 = positive.top();
		positive.pop();
		int num2 = positive.top();
		positive.pop();
		sum += (num1*num2);
	}
	while(!negative.empty())
	{
		int num1 = negative.top();
		negative.pop();
		int num2 = negative.top();
		negative.pop();
		sum += (num1*num2);
	}
	cout << sum + one << "\n";
	return 0;
}      

