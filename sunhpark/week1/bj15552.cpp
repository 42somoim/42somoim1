#include <iostream>

using namespace std;

int		main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int         cnt;
	int			a, b;
	
    cin >> cnt;
    for(int i=0; i < cnt; i++)
    {
        cin >> a >> b;
	    cout << a + b << "\n";
    }
	return (0);
}

