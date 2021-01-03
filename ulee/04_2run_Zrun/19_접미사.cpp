#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s;
    vector<string> v;
    cin >> s;

    for (int i = 0; i < s.length(); ++i) v.push_back(s.substr(i));
    sort(v.begin(), v.end());
    for (auto j : v) cout << j << "\n";
}