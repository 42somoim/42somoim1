#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i<=n; i++) 
    {
        for(int j = 0; j < n -i; j++)
            cout<<" ";
        for(int j =0; j < i; j++)
            cout<<"*";
    cout<<endl;
    }
    for(int i =1; i < n; i++) //  0 1, 2
    {
        for(int j = 0; j <i; j++ ) // j=1 ,  1 < i
            cout<<" ";
        for(int j = 0; j < n -i; j++)
            cout<<"*"; 
        cout<<endl;
    }
}
