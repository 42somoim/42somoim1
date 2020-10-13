
#include<iostream>
#include<queue>
#include<deque>
#include<cmath>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    queue<int> PQ[10];
    deque<int> NQ[10];
    int Arr[1000001] = { 0 };
    int count, maxDigit = 0, digit = 1, N;

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> Arr[i];
        if (Arr[i] < 0)
        {
            maxDigit = max(-Arr[i], maxDigit);
        }
        else
        {
            maxDigit = max(Arr[i], maxDigit);
        }
    }
    while (maxDigit > 10)
    {
        maxDigit /= 10;
        digit++;
    }
    for (int i = 0; i < digit; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (Arr[j] < 0)
            {
                if (-Arr[j] >= (int)pow(10, i))
                {
                    N = -Arr[j] / (int)pow(10, i) % 10;
                    NQ[N].push_back(Arr[j]);
                }
            }
            else
            {
                N = Arr[j] / (int)pow(10, i) % 10;
                PQ[N].push(Arr[j]);
            }
        }
        int idx = 0;
        for (int j = 9; j > -1; j--)
        {
            while (NQ[j].empty() == false)
            {
                Arr[idx] = NQ[j].front();
                NQ[j].pop_front();
                idx++;
            }
        }

        for (int j = 0; j < 10; j++)
        {
            while (PQ[j].empty() == false)
            {
                Arr[idx] = PQ[j].front();
                PQ[j].pop();
                idx++;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << Arr[i] << "\n";
    }
    return (0);
}