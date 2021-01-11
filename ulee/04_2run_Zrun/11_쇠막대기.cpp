#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    string s;
    stack<char> st;
    int result = 0;
    
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') st.push('(');
        else
        {
            st.pop();
            if (s[i - 1] == '(') result += st.size();
            else result++;
        }
    }
    printf("%d", result);
}