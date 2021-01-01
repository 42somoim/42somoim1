#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

int *random_array(int num)
{
    int *lotto_arr;
    vector<int> dup_check(num + 1, 0);
    int ran_num;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, num);

    if (!(lotto_arr = (int *)malloc(sizeof(int) * (num + 1))))
        return (0);
    srand((unsigned int)time(0));
    for (int i = 0; i < num; i++)
    {
        ran_num = dis(gen);
        if (dup_check[ran_num] == 0)
        {
            lotto_arr[i] = ran_num;
            dup_check[ran_num] = 1;
        }
        else
        {
            while(dup_check[ran_num] == 1)
                ran_num = dis(gen);  
            lotto_arr[i] = ran_num;
            dup_check[ran_num] = 1;
        }   
    }
    return (lotto_arr);
}

int main()
{
    int *arr = random_array(5);
    int i = 0;
    while (arr[i])
    {
        cout << arr[i] << endl;
        i++;
    }
}