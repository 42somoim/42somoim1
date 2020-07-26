#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int N = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N-i-1; j++)
            cout << " ";
        for (int j = 0; j < 2*(i+1)-1; j++)
            if (j % 2 == 0)
                cout << "*";
            else
                cout << " ";
                
        cout << endl;
    }
}
