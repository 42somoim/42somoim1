#include <iostream>
#include <queue>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, m;
    queue<int> q;
 
    cin >> n >> m;
 
    for (int i = 1; i <= n; i++)
        q.push(i);
 
    cout << "<";
    while (q.size())
	{
        if (q.size() == 1)
        {
            cout << q.front() << ">";
            q.pop();
            break;
        }
        for (int i = 1; i < m; i++)
		{
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;
    return 0;
}
