#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
 
using namespace std;
 
bool ss(pair<int, int>& a, pair<int, int>& b)
{
    if (b.first > a.first)
        return true;
    else if (b.first == a.first)
    {
        if (b.second > a.second)
            return true;
        else
            return false;
    }
    else
        return false;
}
 
int main() {
    vector <pair<int, int>> v;
    int N;
    scanf("%d", &N);
 
    v.resize(N);
 
    for (int i = 0; i < N; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
 
    sort(v.begin(), v.end(),ss);
 
    for(int i = 0; i < N; i++)
        printf("%d %d\n", v[i].first, v[i].second);
    
 
}

