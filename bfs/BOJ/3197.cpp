#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int r, c;
int lx, ly; // 어떤 한 백조의 위치
int cnt = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visQ[1502][1502]; // 얼음 녹이기 BFS의 방문 체크 배열
int visLQ[1502][1502]; // 백조 찾기 BFS의 방문 체크 배열
string board[1502];
queue <pair<int, int>> Q; 
queue <pair<int, int>> nextQ; // 다음 턴 얼음 녹이기 BFS의 시작점들을 넣은 큐
queue <pair<int, int>> LQ;
queue <pair<int, int>> nextLQ; // 다음 턴  백조 찾기 BFS의 시작점들을 넣은 큐

int main(void){
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> board[i];

    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (board[i][j] == 'L'){
                lx = i;
                ly = j;
            }
            if (board[i][j] != 'X') {
                Q.push({i, j}); // 얼음 녹이기 BFS 시작점 큐에 넣기
                visQ[i][j] = 1;
            }
        }
    }

    LQ.push({lx, ly}); // 백조 찾기 BFS 시작점 큐에 넣기
    board[lx][ly] = '.'; // BFS로 찾은 백조가 자기 자신인 경우를 막기 위해
    visLQ[lx][ly] = 1;

    bool isPossible = false;
    while (!isPossible){

        //얼음 녹이기 BFS
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (visQ[nx][ny]) continue;
                if(board[nx][ny] == 'X') { // 얼음 발견
                    nextQ.push({ nx, ny }); // 다음 턴의 시작점이므로 nextQ에 좌표 넣기
                    board[nx][ny] = '.'; // 얼음 녹이기
                }
                visQ[nx][ny] = 1;
            }
        }

        Q = nextQ;
        nextQ = queue<pair<int, int>>(); // 초기화 필수!!

        cnt++;

        //백조 찾기 BFS
        while (!LQ.empty()){
            auto cur = LQ.front(); LQ.pop();
            for (int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (visLQ[nx][ny]) continue;
                if (board[nx][ny] == 'L'){ // 백조 발견
                    isPossible = true;
                    break;
                }
                else if (board[nx][ny] == 'X'){ // 얼음 발견 => 다음날 녹기 때문에 다음 턴 백조 찾기 BFS의 시작점
                    visLQ[nx][ny] = 1;
                    nextLQ.push({nx, ny});
                    continue;
                }             
                visLQ[nx][ny] = 1;
                LQ.push({nx, ny});
            }
        }
        LQ = nextLQ;
        nextLQ = queue<pair<int, int>>(); // 초기화 필수!!
    }
    cout << cnt;
    return 0;
}

/*
💖 한번에 BFS에 완료되지 않아 다음 BFS의 시작점을 기억해야 하는 BFS
- 한 백조가 다른 백조를 만날 때까지 얼음 녹이기 BFS와 백조 찾기 BFS를 반복해야 한다.
- 이때 각 BFS는 한 번에 완료되지 않아 다음 턴 BFS의 시작점을 기억해야 한다.
- 각각 하나의 임시 큐가 추가로 필요하여 총 네 개의 큐를 이용해야 한다.
*/

// https://www.acmicpc.net/problem/3197