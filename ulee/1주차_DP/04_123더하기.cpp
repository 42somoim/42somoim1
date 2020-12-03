#include <iostream>

using namespace std;
int main(){
    int n;
    int testCase;
    int result[11] = {0};

    cin >> testCase;
    for(int t = 0; t < testCase; t++)
    {
        cin >> n;
        result[1] = 1;
        result[2] = 2;
        result[3] = 4;
        for(int i = 4; i <= n; i++)
            result[i] = result[i - 3] + result[i - 2] + result[i - 1];
        cout << result[n] << endl;
    }
    return (0);
}
