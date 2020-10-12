#include <iostream>
#include <string>

using namespace std;

int main() {
    int i;
    char c;
    string temp;
    char temp2[100];
    getline(cin, temp);

    for (i = 0; i < temp.length(); i++) {
        c = temp[i];
        if (islower(c)) {
            if (c + 13 > 122) c = (c + 13) - 26;
            else c = c + 13;
        }
        if (isupper(c)) {
            if (c + 13 > 90) c = (c + 13) - 26;
            else c = c + 13;
        }
        cout << c;
    }
    cout << endl;


    return 0;
}