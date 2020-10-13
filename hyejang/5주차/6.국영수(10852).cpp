#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>

using namespace std;

class People {
public:
    string name;
    int lang;
    int eng;
    int math;
    People(string name, int lang, int eng, int math) :name(name), lang(lang), eng(eng), math(math) {}
};


bool compare(People a, People b)
{
    if (a.lang > b.lang)
    {
        return a.lang > b.lang;
    }
    else if (a.lang == b.lang && a.eng < b.eng)
    {
        return a.eng < b.eng;
    }
    else if (a.lang == b.lang && a.eng == b.eng && a.math > b.math)
    {
        return a.math > b.math;
    }
    else if(a.lang == b.lang && a.eng == b.eng && a.math == b.math)
    {
        return a.name < b.name;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int count, lang, eng, math;
    string name;
    vector<People> people;

    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> name;
        cin >> lang;
        cin >> eng;
        cin >> math;
        people.push_back(People(name, lang, eng, math));
    }
    stable_sort(people.begin(), people.end(), compare);
    for (int i = 0; i < count; i++)
    {
        cout << people[i].name << "\n";
    }
    return 0;
}