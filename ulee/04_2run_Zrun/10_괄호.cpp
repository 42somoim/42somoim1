#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N, pair, index, flag;
    string S;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {  
        cin >> S;
        index = S.length() - 1;
        pair = 0; flag = 0;
        for (int j = index; j >= 0; j--)
        {
            if (S[j] == ')') pair++;
            else pair--;
            if (pair < 0) flag = 1;
        }
        if (pair == 0 && !flag)
            printf("%s\n", "YES");
        else
            printf("%s\n", "NO");
    }
}