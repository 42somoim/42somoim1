#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>

using namespace std;

class People {
public:
    string name;
    int age;
    People(string name, int age) :name(name), age(age) {}
};


bool compare(People a, People b)
{
    if (a.age < b.age)
    {
        return a.age < b.age;
    }
    else
    {
        return 0;
    }
}

//stable_sort
//sort는 같은 값에 대해 원래의 순서를 유지해준다는 보장이 없다 !
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int count, age;
    string name;
    vector<People> people;

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> age;
        cin >> name;      
        people.push_back(People(name, age));
    }

    stable_sort(people.begin(), people.end(), compare);
    for (int i = 0; i < count; i++)
    {
        cout << people[i].age << " " << people[i].name << "\n";
    }
    return 0;
}