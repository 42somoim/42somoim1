#include <iostream>
#include <string>
using namespace std;

int main(){
	int size;
	cin >> size;

	for (int i = 0; i < size; i++){
		string s;
		cin >> s;
		int count = 0;
		for (int j = 0; j < s.length() && count >= 0; j++){
			if (s[j] == '(') count++;
			else count--;
		}

		if (count ==0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
