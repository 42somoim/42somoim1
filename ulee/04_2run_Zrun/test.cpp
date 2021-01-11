#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
using namespace std;

int main()
{
    list<int> li;
    list<int>::iterator it;
    vector<int> v;
    int N;

    N = 7;
    for (int i = 1; i <= N; ++i) li.push_back(i);

    it = li.begin();
    for (int i = 0; i < N + 10; ++i)
    {
        if (it == li.begin()) cout << *it << " begin!\n";
        if (it == li.end()) cout << *it << " end!\n";
        else if (*it == 1) 
        {
            cout << *it << " erase before!\n";
            it = li.erase(it);
            cout << *it << " erase after!\n";
            if (it == li.begin()) cout << "begin\n";
        }
        else cout << *it << endl; 
        it++;
    }
}

// input = 입력 - 평균값이 높아지는지 낮아지는지도 피드백
// avg = 평균값 출력
// avg_member = 평균값에 가까운 멤버 출력
// avg_hater = 평균값에 가장 먼 멤버 출력
// avg_lot = 가장 많은 멤버 출력
// avg_min = 가장 적은 멤버 출력
// avg_what(숫자) = 해당 점수를 맞추기 위해 필요한 입력값 출력