#include <iostream>

using namespace std;

int main(void)
{
    int t;
    int arr[10001] = {0};
    int a;

    scanf("%d", &t);
    for (int i=0; i < t; i++)
    {
        a=0;
        scanf("%d", &a);
        arr[a]++;
    }

    for (int i=0; i <= 10000; i++)
        for (int j=0; j < arr[i]; j++)
            printf("%d\n", i);
}

