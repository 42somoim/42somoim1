#include <iostream>
#include <string>

using namespace std;

int main(void)
{
        string s;
        cin >> s;

        int pipe = 0, result = 0;
        char prev;

        for (int i = 0; i < s.length(); i++)
        {

                 if (s[i] == '(')

                         pipe++;
                 else
                 {

                         pipe--;
                         if (prev == '(')
                                 result += pipe;
                         else
                                 result++;
                 }
                 prev = s[i];
        }
        cout << result << "\n";
        return 0;
}
