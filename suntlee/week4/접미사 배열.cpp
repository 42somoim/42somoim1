#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string str;
	string temp[1000];
	cin >> str;

	int l = str.length();
	for(int i=0; i<l; i++)
		temp[i] = str.substr(i, l); 

	sort(temp, temp+l);
	for(int i=0; i<l; i++)
		cout << temp[i] << endl;
	
}