#include <iostream>

using namespace std;

/* check if the number exists in the row or column */
int board[10][10];

bool	all_filled() {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			if (board[y][x] == 0) {
				return false;
			}
		}
	}
	return true;
}

bool	row_check(int row, int num) {
	for (int col = 0; col < 9; col++) {
		if (board[row][col] == num) {
			return false;
		}
	}
	return true;
}

bool	col_check(int col, int num) {
	for (int row = 0; row < 9; row++) {
		if (board[row][col] == num) {
			return false;
		}
	}
	return true;
}

bool	box_check(int row, int col, int num) {
	int box_y = row / 3;
	int box_x = col / 3;
	for (int y = box_y * 3; y < (box_y + 1) * 3; y++) {
		for (int x = box_x * 3; x < (box_x + 1) * 3; x++) {
			if (board[y][x] == num) {
				return false;
			}
		}
	}
	return true;
}

void	solve(int x, int y) {
	/* all number is filled */
	if (y == 9) {
		for (int y = 0; y < 9; y++) {
			for (int x = 0; x < 9; x++) {
				cout << board[y][x] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}

	int nx, ny;
	if (x == 8) {
		nx = 0;
		ny = y + 1;
	} else {
		nx = x + 1;
		ny = y;
	}

	if (board[y][x] != 0) {
		solve(nx, ny);
	} else {
		for (int n = 1; n <= 9; n++) {
			if (row_check(y, n) && col_check(x, n) && box_check(y, x, n)) {
				board[y][x] = n;
				solve(nx, ny);
				board[y][x] = 0;
			}
		}
	}
}

int		main(void)
{
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			int num;
			cin >> num;
			board[y][x] = num;
		}
	}
	solve(0, 0);
	return 0;
}
