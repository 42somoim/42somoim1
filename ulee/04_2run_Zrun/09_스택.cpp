#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N, arg, index = 0;
    int stack[10000];
    string S;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {  
        cin >> S;
        switch (S[0])
        {
            case 'p':
                if (S[1] == 'u')
                {
                    scanf("%d", &arg);
                    stack[index] = arg;
                    index++;
                }
                else
                {
                    if (index == 0) printf("%d\n", -1);
                    else
                    {
                        printf("%d\n", stack[index -1]); index--;
                    }
                }
                break;
            case 't':
                if (index == 0)
                    printf("%d\n", -1);
                else
                    printf("%d\n", stack[index - 1]);
                break;
            case 's':
                printf("%d\n", index);
                break;
            case 'e':
                (index == 0) ? printf("%d\n", 1) : printf("%d\n", 0);
                break;
        }
    }
}