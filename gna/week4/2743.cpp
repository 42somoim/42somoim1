#include <iostream>
 
int main() {
    char i = -1, buf[110];
    scanf("%s", buf);
    while (buf[++i]);
    printf("%d\n", i);
 
    return 0;
}
