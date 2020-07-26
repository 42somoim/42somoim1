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

        int t = 2*(i+1)-1;
        for (int j = 0; j < t; j++)
        {
            if (N <= 2)
                cout << "*";
            else
            {
                if (i != N-1)
                {
                    if (j == 0 || j == t-1)
                        cout << "*";          
                    else
                        cout << " ";         
                }
                else
                    cout << "*";             
            }
        }
        cout << endl;
    }
}
