#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef pair<double, double> coord;

int minho_start[2], minho_end[2], kangho_start[2], kangho_end[2];

coord minho(double p)
{
  return {minho_start[0] + (minho_end[0] - minho_start[0]) * (p / 100),
  			minho_start[1] + (minho_end[1] - minho_start[1]) * (p / 100)};
}

coord kangho(double p)
{
  return {kangho_start[0] + (kangho_end[0] - kangho_start[0]) * (p / 100),
  			kangho_start[1] + (kangho_end[1] - kangho_start[1])*(p/100)};
}

int main(void)
{
  cin >> minho_start[0] >> minho_start[1]
  	>>minho_end[0] >> minho_end[1]
	>>kangho_start[0] >> kangho_start[1]
	>>kangho_end[0] >> kangho_end[1];
  
  double fp = 0,lp = 100, ans = 2e9;
  while (lp - fp >= 1e-10) {
    double k1 = (fp * 2 + lp) / 3, k2 = (fp + 2 * lp) /3;
    coord m_k1 = minho(k1), m_k2 = minho(k2);
    coord k_k1 = kangho(k1), k_k2 = kangho(k2);
    
    double dist_k1 = pow(m_k1.first - k_k1.first, 2) + pow(m_k1.second - k_k1.second, 2);
    double dist_k2 = pow(m_k2.first - k_k2.first, 2) + pow(m_k2.second - k_k2.second, 2);

    ans = min(ans, min(dist_k1, dist_k2));
    
    if(dist_k1 >= dist_k2)
		fp = k1;
    else
		lp = k2;
  }
  cout.setf(ios::fixed);
  cout.precision(10);
  cout << sqrt(ans);
  return 0;
}