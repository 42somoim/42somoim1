#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;

    int len = str.size();
    vector<string> vec;

    for (int i = 0; i < len; i++)
        vec.push_back(str.substr(i, len-i));

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
}
