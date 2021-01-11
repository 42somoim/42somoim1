#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main()
{
    list<int> li;
    list<int>::iterator it;
    vector<int> v;
    int N, K, n;

    cin >> N >> K;
    for (int i = 1; i <= N; ++i) li.push_back(i);

    it = li.begin();
    n = N;
    while (N--)
    {
        for (int i = 0; i < K - 1; i++)
        {
            if (it == li.end()) it = li.begin();
            it++;
            if (it == li.end()) it = li.begin();
        }
        v.push_back(*it);
        it = li.erase(it);
    }
    cout << "<";
    for (int i = 0; i < n - 1; ++i) cout << v[i] << ", ";
    cout << v[v.size() - 1] << ">";
}