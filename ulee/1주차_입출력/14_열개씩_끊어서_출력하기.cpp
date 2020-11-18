#include <iostream>

using namespace std;
int main() {
    string str;
    int i = 0;

    cin >> str;
    while (str[i])
    {
        for (int j = 0; j < 10; j++)
        {
            if (str[i])
            {
                cout << str[i];
                i++;
            }
        }
            cout << endl;
    }
    return 0;
}
