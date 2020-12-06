#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, currentCard[500001], M;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> currentCard[i];
    }
    sort(currentCard, currentCard + N);

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int findingCard;
        int left = 0, right = N - 1, mid;
        bool haveCard = false;

        cin >> findingCard;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (currentCard[mid] == findingCard)
            {
                haveCard = true;
                break;
            }
            else if (currentCard[mid] < findingCard)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (haveCard == false)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << 1 << " ";
        }
    }
    return 0;

}