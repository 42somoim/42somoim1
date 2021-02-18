#include <unistd.h>
#include <stdio.h>

int arr[1000001];

int min(int a,int b)
{
	return (a > b ? b : a);
}

int main()
{
	int num,i;
	scanf("%d",&num);

	arr[1] = 0;
	for(i = 2; i<=num; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if(i % 2 == 0)
			arr[i] = min(arr[i],arr[i/2]+1);
		if(i % 3 == 0)
			arr[i] = min(arr[i],arr[i/3]+1);
	}
	printf("%d\n",arr[n]);
	return 0;
}
