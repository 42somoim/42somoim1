#include <iostream>

using namespace std;

int N;
int arr[500000], tmp[500000];
long long ans = 0;

void merge(int p, int q, int r)
{
	int i = p, j = q + 1, t = p;
	int cnt = 0;

	while (i <= q && j <= r)
	{
		if (arr[i] > arr[j])
		{
			tmp[t++] = arr[j++];
			cnt++;
		}
		else
		{
			tmp[t++] = arr[i++];
			ans += (long long)cnt;
		}
	}
	while (j <= r)
	{
		tmp[t++] = arr[j++];
		cnt++;
	}
	while (i <= q)
	{
		tmp[t++] = arr[i++];
		ans += (long long)cnt;
	}
	for (i = p; i <= r; i++)
		arr[i] = tmp[i];
}

void mergeSort(int p, int r)
{
	int q;
	
	if (p < r)
	{
		q = (p + r) / 2;
		mergeSort(p, q);
		mergeSort(q + 1, r);
		merge(p, q, r);
	}
	
}
int main(void)
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	mergeSort(0, N - 1);
	cout << ans;
	return 0;
}