#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    int A, B;
    int count;
    int nums[30];

    cin >> A >> B;
    cin >> count;
    for (int i = 0; i < count; i++)
        cin >> nums[i];

    int ans = 0;
    for (int i = 0; i < count; i++)
        ans = ans*A + nums[i];

    vector<int> vec;
    int n = ans;
    while(n != 0)
    {
        vec.push_back(n % B);
        n /= B;
    }
    reverse(vec.begin(), vec.end());

    for(int i = 0; i < vec.size(); i++){
        if( i == 0)
            cout << vec[i];
        else
            cout << ' ' << vec[i];       
    }
}