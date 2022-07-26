#include <bits/stdc++.h>
#define EMPTY 0
#define APPLE 1
#define SNAKE 2
using namespace std;

int N, K, L;
int board[102][102];
deque<pair<int, char>> changeInfo;
// 동, 남, 서, 북
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


int main(void) {
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = APPLE;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int x;
		char c;
		cin >> x >> c;
		changeInfo.push_back({ x, c });
	}

	board[1][1] = SNAKE;
	int second = 0;
	deque<pair<int, int>> snake;
	snake.push_back({ 1, 1 });
	int dir = 0;
	while (true) {
		second++;
		int x, y;
		tie(x, y) = snake.back();
		int headX = x + dx[dir];
		int headY = y + dy[dir];
		if (headX < 1  || headX > N || headY < 1 || headY > N) break;
		if (board[headX][headY] == SNAKE) break;
		if (board[headX][headY] == EMPTY) {
			int tailX, tailY;
			tie(tailX, tailY) = snake.front();
			board[tailX][tailY] = EMPTY;
			snake.pop_front();
		}
		snake.push_back({ headX, headY });
		board[headX][headY] = SNAKE;
		if (!changeInfo.empty() && changeInfo.front().first == second) {
			char direction = changeInfo.front().second;
			if (direction == 'L') {
				dir = (dir - 1 + 4) % 4;
			}
			else {
				dir = (dir + 1) % 4;
			}
			changeInfo.pop_front();
		}
	}
	printf("%d\n", second);
	return 0;
}