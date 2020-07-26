#include <iostream>
#include <cstdlib>
using namespace std;

int        main(void)
{
    char       num;;
    int        cnt;
    int        sum;
    int        i;
    
    sum = 0;
    i = 0;
    cin >> cnt;
    while (i < cnt)
    {
		cin >> num;
        sum += num - 48;
        i++;
    }
    cout << sum << "\n";
    return (0);
}


