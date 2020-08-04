#include <stdio.h>;
int Month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char *Day[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main()
{
	int X, Y;
	scanf("%d %d",&X,&Y);
	for(int i = 0; i < X-1; i++)
		Y+=Month[i];
	printf("%s\n",Day[Y%7]);
	return 0;
}
