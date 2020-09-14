#include <iostream>
#include <string>
 
using namespace std;
 
string N;
int B, result;
 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
 
    cin >> N >> B;
    
    int temp = 1;
 
    for (int i = N.size() - 1; i >= 0; i--)
    {
        int n;
        if (N[i] >= '0' && N[i] <= '9') n = N[i] - '0';
        else n = N[i] - 'A' + 10;
        
        n *= temp;
        result += n;
        temp *= B;
    }
    
    cout << result;
 
    return 0;
}