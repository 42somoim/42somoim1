#include <iostream>
using namespace std;

int n;

struct node 
{
    char left;
    char right;
};

struct node arr[26 + 66];

void preOrder(char root) 
{
    if (root == '.')
        return;
    cout << root;
    preOrder(arr[root].left);
    preOrder(arr[root].right);
}

void inOrder(char root) {
    if (root == '.')
        return;
    inOrder(arr[root].left);
    cout << root;
    inOrder(arr[root].right);
}

void postOrder(char root) {
    if (root == '.')
        return;
    postOrder(arr[root].left);
    postOrder(arr[root].right);
    cout << root;
}

int main() 
{
    cin >> n;

    char a, b, c;

    for (int i = 1; i <= n; i++) 
    {
        cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
    }

    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";

    return 0;
}