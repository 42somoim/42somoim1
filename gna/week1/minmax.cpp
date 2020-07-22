#include <iostream>
using namespace std;

int main() 
{
    int n;
    int min=1000000;
    int max=-1000000;
    int num;
     cin>>n;
    for(int i=1; i<=n; i++ )
    {
        cin>>num;
        min=(num<min) ? num:min;
        max=(num>max) ? num:max;
    }
    cout<<min<<" "<<max<<endl; 
}
