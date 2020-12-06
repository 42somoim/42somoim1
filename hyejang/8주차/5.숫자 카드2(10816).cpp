#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, lower;

    cin >> N;
    vector<int> currentCard(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> currentCard[i];
    }
    sort(currentCard.begin(), currentCard.end());

    cin >> M;


    for (int i = 0; i < M; i++)
    {
        int findingCard;
        int left = 0, right = N - 1, mid;

        cin >> findingCard;

        while (right > left)
        {
            mid = (left + right) / 2;
            if (currentCard[mid] >= findingCard)
            {
                right = mid;               
            }
            else
            {
                left = mid + 1;
            }
        }
        lower = right;

        left = 0, right = N - 1, mid;
        while (right > left)
        {
            mid = (left + right) / 2;
            if (currentCard[mid] > findingCard)
            {
                right = mid;           
            }
            else
            {
                left = mid + 1;
            }
        }
        if (right == N - 1 && currentCard[N - 1] == findingCard)
            right++;
        cout << right - lower << " ";
    }
    return 0;

}