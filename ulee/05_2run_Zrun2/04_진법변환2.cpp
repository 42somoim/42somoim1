#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<int> v;
	int N, B;

	cin >> N >> B;
	while (N)
	{
		v.push_back(N % B);
		N /= B;
	}
	for (auto i = v.rbegin(); i != v.rend(); ++i)
	{
		if (*i > 9) printf("%c", *i + 'A' - 10);
		else printf("%d", *i);
	}
	return (0);
}
