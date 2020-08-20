#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
    int N;
    deque<int> dq;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; ++i) {
        string text;
        getline(cin, text);
        if (text == "front") {
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.front() << "\n";
        }
        else if (text == "back") {
            if (dq.empty()) cout << -1 << "\n";
            else cout << dq.back() << "\n";
        }
        else if (text[1] == 'u') {
            string backup = text;
            if (text[5] == 'f') {
                int x = stoi(backup.erase(0, 10));
                dq.push_front(x);
            }
            else {
                int x = stoi(backup.erase(0, 9));
                dq.push_back(x);
            }
        }
        else if (text[1] == 'o') {
            if (text[4] == 'f') {
                if (dq.empty()) cout << -1 << "\n";
                else {
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }
            }
            else {
                if (dq.empty()) cout << -1 << "\n";
                else {
                    cout << dq.back() << "\n";
                    dq.pop_back();
                }
            }
        }
        else if (text == "size")
            cout << dq.size() << "\n";
        else if (text == "empty") {
            if (dq.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
}
