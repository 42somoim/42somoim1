#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int a,b,c,d =0;
    string result1, result2;

    cin >> a >> b >> c >> d;

    result1 = to_string(a) + to_string(b);
    result2 = to_string(c) + to_string(d);

    long long A = stoll(result1);
    long long B = stoll(result2);

    cout << A + B << endl;
    return 0;
}