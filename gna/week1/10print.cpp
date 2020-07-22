#include <iostream>  

using namespace std;

int main(void)
{
	int i;
	char c[100];
	cin >> c;

	for(i=0; i<100; i++)
	{
		if (c[i] == '\0')
			break;
	}	
	for (int j = 0; j < i ; ++j)
	{
		cout << c[j];
		if ((j+1) % 10 == 0)
			cout << endl;
	}
}
