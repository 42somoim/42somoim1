#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return (a.first < b.first);
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, string> > arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;
     
    stable_sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < N; i++)
        cout << arr[i].first << " " << arr[i].second << "\n";
}