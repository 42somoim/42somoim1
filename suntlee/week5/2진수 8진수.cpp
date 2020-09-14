#include <iostream>
#include <map>
#include <deque>

using namespace std;

int main()
{
    string str;
    int size, i = 0;
    deque <char> ans;
    map <string, char> map;
    
    map["000"] = '0';
    map["001"] = '1';
    map["010"] = '2';
    map["011"] = '3';
    map["100"] = '4';
    map["101"] = '5';
    map["110"] = '6';
    map["111"] = '7';
    
    cin >> str;
    size = str.size();
    
    if (size == 1 && str[0] == '0')
        cout << 0;
    else
    {
        while (true)
        {
            if (size-i >= 3)
                ans.push_front(map[str.substr(size-3-i, 3)]);
            else if (size-i == 2)
            {
                str = '0' + str.substr(0, 2);
                ans.push_front(map[str]);
            }
            else if (size-i == 1)
            {
                str = "00" + str.substr(0, 1);
                ans.push_front(map[str]);
            }
            else
                break;
            i += 3;
        }
        
        size = ans.size();
        for (int i = 0; i < size; i++)
            cout << ans[i];
    }
    
    return 0;
}