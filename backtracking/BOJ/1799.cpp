#include <bits/stdc++.h>
using namespace std;


int N;
int board[11][11];
int l[20]; // 왼쪽 위 방향 대각선
int r[20]; // 오른쪽 위 방향 대각선
int res[2];

void sol(int row, int col, int count, int color) {
    if (row >= N) { // 종료 조건
        if (res[color] < count) res[color] = count;
        return;
    }

    if (col >= N) { 
        row++; // 짝수열을 갖는 행은 다음 행에서 홀수열을 갖는다.
        if (col % 2 == 0) col = 1;
        else col = 0;
    }

    if (board[row][col] && !l[col - row + N - 1] && !r[col + row]) {
        l[col - row + N - 1] = r[col + row] = 1;
        sol(row, col + 2, count + 1, color);
        l[col - row + N - 1] = r[col + row] = 0;

    }
    sol(row, col + 2, count, color);
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    sol(0, 0, 0, 0); // 검은색 칸
    sol(0, 1, 0, 1); // 흰색 칸

    cout << res[0] + res[1];
    return 0;
}


/*
🚀 체스판을 두 경우로 나누어 푸는 것이 핵심!!
board[row][col]이라 했을 때 row + col이 짝수인 칸과 row + col이 홀수인 칸은 서로 영향을 주지 않는다.
- row + col이 짝수인 칸 => 검은색 칸
- row + col이 홀수인 칸 => 흰색 칸
=> 두 경우로 나누어 풀어야 한다.
*/

// https://www.acmicpc.net/problem/1799