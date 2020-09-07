#include <iostream>

using namespace std;

int main() {
    int a=0, b=0, c = 0;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> b >> c;
        cout << b + c << endl;
    }
    return 0;
}