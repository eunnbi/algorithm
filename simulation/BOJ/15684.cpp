#include <bits/stdc++.h>
#define MAX 9999999
using namespace std;

int N, M, H;
int res = MAX;
// vis[i][j] : i번 세로선과 i+1번 세로선을 j번 가로선에서 연결되어 있다.
bool ladder[11][30];

bool ladderGame() {
    for (int i = 1; i <= N; i++) {
        int num = i;
        for (int j = 1; j <= H; j++) {
            if (num != N && ladder[num][j]) num += 1;
            else if (num != 1 && ladder[num - 1][j]) num -= 1;
        }
        if (num != i) return false;
    }
    return true;
}

// idx : 몇번째 가로선,  cnt: 추가한 가로선 개수
void sol(int idx, int cnt) {
    if (cnt >= 4) return; // 추가한 가로선 개수가 3보다 큰 값이면 return
    if (ladderGame()) { // 게임 결과 조작이 성공되면 정답값 업데이트하고 return
        if (res > cnt) res = cnt;
        return;
    }
    // 가로선 조합 시도
    for (int i = idx; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            // 가로선이 연속되는 경우 없음
            if (ladder[j][i] || ladder[j - 1][i] || ladder[j + 1][i])  continue;
            ladder[j][i] = true;
            sol(i, cnt + 1);
            ladder[j][i] = false;
        }
    }
}

int main(void) {
    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[b][a] = true;
    }
    sol(1, 0);
    if (res == MAX)  res = -1;
    printf("%d\n", res);
    return 0;
}