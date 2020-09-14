#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int check[300000];

int get_next(int num, int p)
{
    int next = 0;
    while(num != 0){
        next += pow(num % 10, p);
        num /= 10;
    }
    return next;
}

int main()
{

    int node, p;
    cin >> node >> p;

    int cnt = 1;
    check[node] = cnt;

    int next = get_next(node, p);

    while(check[next] == 0){
        cnt += 1;
        check[next] = cnt;
        next = get_next(next, p);
    }

    cout << check[next] - 1;
}