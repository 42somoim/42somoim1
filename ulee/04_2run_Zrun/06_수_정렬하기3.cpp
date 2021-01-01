#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, x;

    vector<int> v(10001, 0);
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x); 
        v[x]++;
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < v[i]; j++) printf("%d\n", i);
    }
}