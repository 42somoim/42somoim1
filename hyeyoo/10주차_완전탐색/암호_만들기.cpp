#include <iostream>
#include <algorithm>
using namespace std;

char arr[16];
bool visited[16];
int length, all;

bool	check_format() {
	int vowel = 0;
	int consonant = 0;
	for (int i = 0; i < all; i++) {
		if (visited[i]) {
			char c = arr[i];
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
				consonant++;
			} else {
				vowel++;
			}
		}
	}
	return (vowel >= 2) && (consonant >= 1);
}

void	solve(int s, int depth) {
	if (depth == length) {
		if (!check_format()) {
			return ;
		}
		for (int i = 0; i < all; i++) {
			if (visited[i]) {
				cout << arr[i];
			}
		}
		cout << '\n';
	} else {
		for (int i = s; i < all; i++) {
			if (!visited[i]) {
				visited[i] = true;
				solve(i + 1, depth + 1);
				visited[i] = false;
			}
		}
	}
}

int		main(void)
{
	cin >> length >> all;
	for (int i = 0; i < all; i++)
		cin >> arr[i];
	sort(arr, arr + all);
	solve(0, 0);
	return 0;
}
