#include <iostream>

using namespace std;
int main()
{
    int N, a, b;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        cout << "Case #" << i + 1 << ": " << a << " + " << b << " = " << a + b << endl;
    }
    return (0);
}
