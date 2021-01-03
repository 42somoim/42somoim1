#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main()
{
    list<char> li;
    list<char>::iterator it;
    string s;
    int N;
    char com, x;

    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        li.push_back(s[i]);
    }
    it = li.end();
    cin >> N;
    while (N--)
    {
        cin >> com;
        if (com == 'L')
        {
            if (it != li.begin()) it--;
        }
        else if (com == 'D')
        {
            if (it != li.end()) it++;
        }
        else if (com == 'B')
        {
            if (it != li.begin()) li.erase(prev(it));
        }
        else if (com == 'P')
        {
            cin >> x; 
            li.insert(it, x);
        }
    }
    for (auto c : li)
        cout << c;
}