#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int MAX = 15;

int L, C;
char alphabet[MAX];
vector<char> vowel;
vector<char> consonant;
vector<string> result;
map<string, bool> visited;

void password(int idx1, int idx2, int v_cnt, int c_cnt, string s)
{
	if (s.length() == L && v_cnt >= 1 && c_cnt >=2)
	{
		sort(s.begin(), s.end());
		if (!visited[s])
		{
			visited[s] = true;
			result.push_back(s);
		}
	}
	if (s.length() == L)
		return ;
	
	for (int i = idx1 + 1; i < vowel.size(); i++)
		password(i, idx2, v_cnt + 1, c_cnt, s + vowel[i]);
	for (int i = idx2 + 1; i < consonant.size(); i++)
		password(idx1, i, v_cnt, c_cnt + 1, s + consonant[i]);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> alphabet[i];
		if (alphabet[i] == 'a' || alphabet[i] == 'e' || alphabet[i] == 'i' || alphabet[i] == 'o' ||
			alphabet[i] == 'u')
			vowel.push_back(alphabet[i]);
		else
			consonant.push_back(alphabet[i]);
	}
	sort(vowel.begin(), vowel.end());
	sort(consonant.begin(), consonant.end());

	password(-1, -1, 0, 0, "");
	sort(result.begin(), result.end());

	for (auto s : result)
		cout << s << '\n';
	return 0;
}
