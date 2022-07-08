#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second


char board[105][105];
int vis[105][105];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string keystr;
int t, h, w;

int main(void){
    cin >> t;
    while (t--){
        cin >> h >> w;

        int cnt = 0;
        
        // vis, board 배열 초기화!! (여러 테스트 케이스 존재)
        for (int i = 0; i <= h + 1; i++){
            for (int j = 0; j <= w + 1; j++){
                vis[i][j] = 0;
                board[i][j] = 0;
            }
        }

        for (int i = 1; i <= h; i++){ // 1-based indexing
            for (int j = 1; j <= w; j++){
                cin >> board[i][j];
            }
        }

        // 'a' ~ 'z'의 키를 가지고 있는지 여부를 저장하는 배열
        bool key[26] = { 0, };  // 초기화 필수!! (여러 테스트 케이스 존재)
        cin >>  keystr;
        for (auto ch : keystr) key[ch - 'a'] = 1;

        queue<pair<int, int>> Q;
        queue<pair<int, int>> door[26]; // 👉 아직 키가 없어서 방문하지 못한 곳의 좌표를 저장. 추후 키가 생기면 방문 예정.
        Q.push({ 0, 0 });
        vis[0][0] = 1;

        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            for (int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;
                if (vis[nx][ny] || board[nx][ny] == '*') continue;

                // 1. 열쇠 발견
                if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {
                    int k = board[nx][ny] - 'a';
                    key[k] = 1;
                    // 👉 전에는 방문하지 못했지만, 발견된 열쇠롤 방문할 수 있는 칸을 bfs queue에 넣기
                    while (!door[k].empty()) { 
                        auto ndoor = door[k].front(); door[k].pop();
                        Q.push({ ndoor.X, ndoor.Y });
                    }
                 }

                 // 2. 문 발견
                 else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') {
                    int k = board[nx][ny] + 32 - 'a'; // 소문자로 변환
                    if (!key[k]) { // 👉 문을 열 수 있는 키가 없으면 door queue에 좌표 넣기
                        door[k].push({ nx, ny });
                        continue;
                    }
                 }

                 // 3. 문서 발견
                 else if (board[nx][ny] == '$') cnt++;

                 vis[nx][ny] = 1;
                 Q.push({ nx, ny });
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

/*
👉 지금은 방문할 수 없지만, 나중에 방문할 수 있는 가능성 있는 칸이 존재하는 BFS
- 지금은 방문할 수 없지만, 나중에 방문할 수 있는 칸을 다른 queue에 넣기
- 추후에 방문이 가능하다면 bfs 수행하는 queue에 넣기

👉 시작점 제시 X
- 처음에 빌딩 밖에 있다고 가정한 상황
- 빌딩 배열 - 1 ~ h, 1 ~ w (1-based indexing)
- 빌딩 배열 + 빌당 밖 - 0 ~ h + 1, 0 ~ w + 1 으로 인덱스 범위 확장
*/
// https://www.acmicpc.net/problem/9328