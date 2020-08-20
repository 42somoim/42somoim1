#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string str;
    cin >> str;
 
    for (char a = 'a'; a <= 'z'; a++)
        cout << count(str.begin(), str.end(), a) << ' ';
 
    cout << endl;
    return 0;
}