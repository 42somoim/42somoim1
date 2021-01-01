#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int N, temp;
    vector<int> arr;
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
}