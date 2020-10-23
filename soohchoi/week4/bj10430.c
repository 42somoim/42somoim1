#include<stdio.h>

int main()
{
    int a;
    int b;
    int c;
    
    scanf("%d%d%d", &a, &b, &c);
    if(!(a>=2 && a<=10000 && b>=2 && b<=10000 && c>=2 && c<=10000))
        return 0;
    printf("%d\n%d\n%d\n%d\n", (a+b)%c, ((a%c)+(b%c))%c, (a*b)%c, ((a%c)*(b%c))%c);
    return 0;
}
