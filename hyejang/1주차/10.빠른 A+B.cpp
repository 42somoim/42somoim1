#include <cstdio>


int main() {

    int a, b, c;

    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf("%d %d", &b, &c);
        printf("%d\n", b + c);
    }
    return 0;
}