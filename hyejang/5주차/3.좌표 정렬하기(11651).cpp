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
    if (a.name == b.name) 
    {
        return 0;
    }
    else 
    {
        return a.age < b.age;
    }
}

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
        cin >> name;
        cin >> age;
        people.push_back(People(name, age));
    }

    sort(people.begin(), people.end(), compare);
    for (int i = 0; i < count; i++)
    {
        cout << people[i].age << " " << people[i].name << "\n";
    }
    return 0;
}