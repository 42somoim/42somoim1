#include <iostream>

using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, a, b;

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        cout << a + b << "\n";
    }
}
