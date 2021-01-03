#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> v;
    int N, K, who_kill, now_len;
    
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) v.push_back(i);

    who_kill = 0;
    now_len = N;
    cout << "<";
    for (int i = 0; i < N; ++i)
    {
        who_kill = (who_kill + K - 1) % now_len;
        cout << v[who_kill];
        std::remove(v.begin(), v.end(), v[who_kill]);
        --now_len;
        if (i == N - 1) cout << ">\n";
        else cout << ", ";
    }
    return (0);
}