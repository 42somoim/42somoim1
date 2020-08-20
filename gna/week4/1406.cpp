#include <cstdio>
#include <list>
#include <iterator>
#include <string>
#include <iostream>

using namespace std;

void printlist(list<char> l) {
    for(list<char>::iterator iter = l.begin(); iter != l.end(); iter++) {
        cout << *iter;
    }
    cout << endl;
}
int main () {
    string str, input;
    list<char> l;
    int N, i;
    char buf;

    cin >> str;
    scanf("%d%c", &N, &buf);
    for (i = 0; i < str.length(); i++) {
        l.push_back(str[i]);
    }

    list<char>::iterator iter = l.end();

    for (i = 0; i < N; i++) {
        getline(cin, input);
        if (input[0] == 'L') {
            if (iter != l.begin()) iter--;
        }
        else if (input[0] == 'D') {
            if (iter != l.end()) iter++;
        }
        else if (input[0] == 'B') {
            if (iter != l.begin()) iter = l.erase(--iter);
        }
        else {
            l.insert(iter, input[2]);
        }
    }

    printlist(l);
    return 0;
}
