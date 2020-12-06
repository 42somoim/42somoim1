#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<double, double> pii;

typedef struct Pos
{
    int xpos;
    int ypos;
}pos;

pos minho_start_pos;
pos minho_end_pos;
pos gangho_start_pos;
pos gangho_end_pos;

pii minho_move(double p)
{
    return make_pair(minho_start_pos.xpos + (minho_end_pos.xpos - minho_start_pos.xpos) * (p / 100), minho_start_pos.ypos + (minho_end_pos.ypos - minho_start_pos.ypos) * (p / 100));
}

pii kangho_move(double p)
{
    return make_pair(gangho_start_pos.xpos + (gangho_end_pos.xpos - gangho_start_pos.xpos) * (p / 100), gangho_start_pos.ypos + (gangho_end_pos.ypos - gangho_start_pos.ypos) * (p / 100));
}

int main()
{
    //lenght의 최대길이 -> 10000 - 0
    double first_percent = 0, last_percent = 100, length = sqrt(pow(10000, 2) + pow(10000, 2));

    cin >> minho_start_pos.xpos >> minho_start_pos.ypos;
    cin >> minho_end_pos.xpos >> minho_end_pos.ypos;
    cin >> gangho_start_pos.xpos >> gangho_start_pos.ypos;
    cin >> gangho_end_pos.xpos >> gangho_end_pos.ypos;

    while (last_percent - first_percent >= 1e-7)
    {
        double p1, p2;
        // 첫 삼등분 좌표 -> 33.33333 & 66.66666
        p2 = (first_percent + 2 * last_percent) / 3, p1 = (2 * first_percent + last_percent) / 3;

        // 33%, 66% 갔을때 얼마나 움직였는가
        pii m1 = minho_move(p1), m2 = minho_move(p2);
        pii k1 = kangho_move(p1), k2 = kangho_move(p2);

        // 33%, 66% 일때 서로의 길이를 체크
        double len_p1 = sqrt(pow(m1.first - k1.first, 2) + pow(m1.second - k1.second, 2));
        double len_p2 = sqrt(pow(m2.first - k2.first, 2) + pow(m2.second - k2.second, 2));

        length = min(min(len_p1, len_p2), length);
        //p2의 길이가 더 길면(서로의 길이가 더 멀면)
        //좌표값을 왼쪽부터 다시 검색하도록 last_percent값을 줄임 
        if (len_p1 <= len_p2)
        {
            last_percent = p2;
        }
        else
        {
            first_percent = p1;
        }
    } 
    cout.precision(7);
    cout << length << "\n";

    return 0;
}
