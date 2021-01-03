#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, arg;
    int front = 10001, back = 10001;
    int deck[20002];
    string s;

    cin >> N;
    for (int j = 0; j < N; j++)
    {
        cin >> s;
        if (s[1] == 'u')
        {
            cin >> arg;
            if (s[5] == 'f')
                deck[front--] = arg;
            else
                deck[++back] = arg;
        }
        else if (s[1] == 'o')
        {
            if (s[4] == 'f')
            {
                if (front == back) cout << "-1\n";
                else cout << deck[++front] << "\n";
            }
            else
            {
                if (front == back) cout << "-1\n";
                else cout << deck[back--] << "\n";
            }
        }
        else if (s[1] == 'i')
        {
            cout << back - front << "\n";
        }
        else if (s[1] == 'm')
        {
            if (front == back) cout << "1\n";
            else cout << "0\n";
        }
        else if (s[1] == 'r')
        {
            if (front == back) cout << "-1\n";
            else cout << deck[front + 1]<< "\n";
        }
        else if (s[1] == 'a')
        {
            if (front == back) cout << "-1\n";
            else cout << deck[back]<< "\n";
        }

    }

}