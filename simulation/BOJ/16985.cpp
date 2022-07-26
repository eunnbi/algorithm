#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int board[5][5][5]; // 원본 유지
int rotated[5][5][5];
int final[5][5][5];
int vis[5][5][5];
int dx[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 1, 0, -1, 0, 0, 0 };
int res = MAX;


void initialize() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				rotated[i][j][k] = board[i][j][k];
 			}
		}
	}
}


void rotate(int num, int dir) {
	if (dir == 0) return;
	int tmp[5][5] = { 0, };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			tmp[i][j] = rotated[num][i][j];
		}
	}
	if (dir == 1) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				rotated[num][j][k] = tmp[4 - k][j];
			}
		}
	}
	else if (dir == 3) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				rotated[num][j][k] = tmp[k][4 - j];
			}
		}
	}
	else {
		while (dir--) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					rotated[num][j][k] = tmp[4 - k][j];
				}
			}
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					tmp[j][k] = rotated[num][j][k];
				}
			}
		}
	}
}



int main(void) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> board[i][j][k];
			}
		}
	}


	int total = 1 << (2 * 5); // 5개판을 회전하는 총 경우의 수
	for (int i = 0; i < total; i++) {
		initialize();
		int brute = i;
		// 5개의 판 회전하기
		for (int j = 0; j < 5; j++) {
			int dir = brute % 4;
			brute /= 4;
			rotate(j, dir);
		}
		// 5개판 쌓고 bfs
		int num[5] = { 0, 1, 2, 3, 4 };
		do {
			// num 배열에 따라 5개판 쌓기
			for (int j = 0; j < 5; j++) {
				for (int r = 0; r < 5; r++) {
					for (int c = 0; c < 5; c++) {
						final[j][r][c] = rotated[num[j]][r][c];
						vis[j][r][c] = 0;
					}
				}
			}

			// bfs
			if (!final[0][0][0] || !final[4][4][4]) continue;
			vis[0][0][0] = 1;
			queue<tuple<int, int, int, int>> Q;
			Q.push({ 0, 0, 0, 0 });
			while (!Q.empty()) {
				int curX, curY, curZ, cnt;
				tie(curX, curY, curZ, cnt) = Q.front(); Q.pop();
				if (curX == 4 && curY == 4 && curZ == 4) {
					if (res > cnt) res = cnt;
					break;
				}
				for (int k = 0; k < 6; k++) {
					int nx = curX + dx[k];
					int ny = curY + dy[k];
					int nz = curZ + dz[k];
					if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
					if (!final[nx][ny][nz] || vis[nx][ny][nz]) continue;
					vis[nx][ny][nz] = 1;
					Q.push({ nx, ny, nz, cnt + 1 });
				}
			}
		} while (next_permutation(num, num + 5)); // 판 쌓는 순서
	}
	if (res == MAX) {
		printf("-1\n");
	}
	else {
		printf("%d\n", res);
	}
	return 0;
}