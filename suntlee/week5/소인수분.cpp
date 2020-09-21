#include <cstdio>
#include <cmath>

using namespace std;

int main()
{

    int N, i, j;

    scanf("%d", &N);

    for (i = 2; i <= sqrt(N); i++)
	{
        while(N%i == 0) {
            printf("%d\n", i);
            N /= i;
        }
    }

    if (N != 1) printf("%d\n", N);

    return 0;
}