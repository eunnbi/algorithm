#include <bits/stdc++.h>
using namespace std;

int N;
int paper[2200][2200];
int cnt[3]; // -1, 0, 1로 채워진 종이 갯수


// 종이 내부에 같은 숫자로만 채워졌는지 확인하는 함수
// x, y : 종이의 시작점, z : 종이의 한 변의 길이
bool check(int x, int y, int z){
    for (int i = x; i < x + z; i++){
        for (int j = y; j < y + z; j++){
            if (paper[x][y] != paper[i][j])
                return false;
        }
    }
    return true;
}

// x, y : 종이의 시작점, z : 종이의 한 변의 길이
void sol(int x, int y, int z){
    if (check(x, y, z)){
        cnt[paper[x][y] + 1] += 1; 
        return;
    }

    int n = z / 3; // 한변의 길이가 3분의 1로 줄어듦.
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            sol(x + i * n, y + j * n, n);
        }
    }

}


int main(void){
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> paper[i][j];
        }
    }
    sol(0, 0, N);
    for (int i = 0; i < 3; i++) cout << cnt[i] << '\n';
    return 0;
}

// 👉 종이를 시작점 좌표와 한 변의 길이로 나타내는 것이 중요!
// https://www.acmicpc.net/problem/1780