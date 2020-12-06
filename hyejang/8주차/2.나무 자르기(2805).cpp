#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    long left = 0, right = 1, max_line_length = 0, mid, wood, tree[1000001] = { 0 };
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        tree[i] = tmp;
        right = max(tree[i], right);
    }
    while (1)
    {
        wood = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < N; i++)
        {
            if (tree[i] > mid)
            {
                wood += tree[i] - mid;
            }
        }
        if (right < left)
        {
            break;
        }
        if (wood > M)
        {
            left = mid + 1;
        }
        else if (wood == M)
        {
            break;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << mid << "\n";
    return 0;
}


