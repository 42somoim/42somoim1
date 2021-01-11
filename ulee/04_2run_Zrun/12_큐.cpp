#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int que[10000];
    string s;
    char c;
    int N, x;
    int front = 0, back = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        switch (s[1])
        {
            case 'u':
                scanf("%d", &x);
                que[back] = x;
                back++;
                break;
            case 'o':
                if (front == back)
                    printf("%d\n", -1);
                else
                {
                    printf("%d\n", que[front]);
                    front++;
                }
                break;
            case 'i':
                printf("%d\n", back - front);
                break;
            case 'm':
                (front == back) ? printf("%d\n", 1) : printf("%d\n", 0); 
                break;
            case 'r':
                (front == back) ? printf("%d\n", -1) : printf("%d\n", que[front]); 
                break;
            case 'a':
                (front == back) ? printf("%d\n", -1) : printf("%d\n", que[back - 1]); 
                break;  
        }
    }

}