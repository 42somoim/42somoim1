#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int arr[123] = {0};
    string s;

    cin >> s;    
    int i = 0;
    while (s[i])
    {
        arr[s[i]]++; i++;
    }

    for (int j= 97; j <= 122; j++)
        cout << arr[j] << " ";
}