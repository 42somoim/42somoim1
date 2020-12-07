#include <iostream>

using namespace std;
int main()
{
    int month, day;
    int arr_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string day_name[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    cin >> month >> day;
    for (int i = 0; i < month - 1; i++)
        day += arr_month[i];
    day %= 7;
    cout << day_name[day];
}
