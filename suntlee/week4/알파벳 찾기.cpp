#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string str;
    cin >> str;
 
    int idx;
    for (char a = 'a'; a <= 'z'; a++)
	{
        idx = str.find(a);
        cout << idx << ' ';
    }
 
    cout << endl;
    return 0;
}
