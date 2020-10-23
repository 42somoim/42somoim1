#include <iostream>
#include <algorithm>

using namespace std;

bool visited[201][201][201];
const int MAX = 200;
bool answered[201];
int ans = 0;
int max_a, max_b, max_c;

void	solve(int A, int B, int C) {
	int x, y, z;
	visited[A][B][C] = true;

	/* A->B */
	x = A; y = B; z = C;
	int sum = x + y;
	y = min(max_b, sum);
	x = sum - y;
	if (!visited[x][y][z])
		solve(x, y, z);

	/* A->C */
	x = A; y = B; z = C;
	sum = x + z;
	z = min(max_c, sum);
	x = sum - z;
	if (!visited[x][y][z])
		solve(x, y, z);

	/* B->A */
	x = A; y = B; z = C;
	sum = x + y;
	x = min(max_a, sum);
	y = sum - x;
	if (!visited[x][y][z])
		solve(x, y, z);

	/* B->C */
	x = A; y = B; z = C;
	sum = y + z;
	z = min(max_c, sum);
	y = sum - z;
	if (!visited[x][y][z])
		solve(x, y, z);

	/* C->A */
	x = A; y = B; z = C;
	sum = x + z;
	x = min(max_a, sum);
	z = sum - x;
	if (!visited[x][y][z])
		solve(x, y, z);
	/* C->B */
	x = A; y = B; z = C;
	sum = x + z;
	x = min(max_a, sum);
	z = sum - x;
	if (!visited[x][y][z])
		solve(x, y, z);
}

int	main(void)
{
	cin >> max_a >> max_b >> max_c;
	solve(0, 0, max_c);

	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			if (visited[0][j][i] && !answered[i]) {
				cout << i << ' ';
				answered[i] = true;
			}
		}
	}
	cout << endl;
	return 0;
}
