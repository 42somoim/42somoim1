#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> v;

void printCard(void)
{
  sort(v.begin(), v.end());

  int cnt = 1, maxcnt = 0;
  long long card;

  for (int i = 1; i < N; i++)
  {
    if (v[i - 1] != v[i] && maxcnt < cnt)
    {
      maxcnt = cnt;
      card = v[i - 1];
      cnt = 1;
    }
    else if (v[i - 1] != v[i] && maxcnt >= cnt)
      cnt = 1;
    else
      cnt++;
  }
  if (maxcnt < cnt)
    card = v[N-1];
  cout << card << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    long long num;
    cin >> num;

    v.push_back(num);
  }

  printCard();
  return 0;
}
