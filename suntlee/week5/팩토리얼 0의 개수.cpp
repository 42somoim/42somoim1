#include <cstdio>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);	// 문서갯수, 궁금한 위치

    // 0팩토리얼 예외 처리
	if(n==0)
	{
		printf("0\n");
		return (0);
	}
	// 5의 배수일 경우 0이 한개씩 발생
	// 25의 배수일 경우 0이 한개 더 발생
	// 125의 배수일 경우 0이 한개 더 발생
	int count_0 = 0;
	for(int i = 2; i <= n; ++i)
	{
		if(i % 5 == 0) count_0++;
		if(i % 25 == 0) count_0++;
		if(i % 125 == 0) count_0++;
	}
	printf("%d\n", count_0);
	return 0;
}