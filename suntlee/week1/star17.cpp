#include<cstdio>
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + i; j++) printf(i==n-1||j == n - 1 - i || j == n - 1 + i ? "*" : " ");
		puts("");
	}
	return 0;
}
