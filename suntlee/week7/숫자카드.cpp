#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int N;
        cin >> N;

        vector<int> v(N);
        for (int i = 0; i < N; i++)
			cin >> v[i];
        sort(v.begin(), v.end());

        int M;
        cin >> M;

        for (int i = 0; i < M; i++)
        {
			int num;
			cin >> num;

			int low = 0, high = N - 1;
			bool searched = false;
			while (low <= high)
			{
				int mid = (low + high) / 2;
				if (v[mid] == num)
				{
					searched = true;
					break;
				}
				else if (v[mid] < num)
					low = mid + 1;
				else
					high = mid - 1;
			}
			if (!searched)
				cout << 0 << " ";
			else
				cout << 1 << " ";
        }
        return 0;
}
