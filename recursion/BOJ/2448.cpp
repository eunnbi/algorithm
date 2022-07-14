#include <bits/stdc++.h>
using namespace std;

int N;
int res[3500][6500];


char star[3][5] = {
    { ' ', ' ', '*', ' ', ' '},
    { ' ', '*', ' ', '*', ' '},
    { '*', '*', '*', '*', '*'}
};

void sol(int x, int y, int n){
    if (n == 3){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 5; j++){
                res[x + i][y + j] = star[i][j];
            }
        }
        return;
    }

    // 🙌 좌표가 어떻게 나누어지는기 파악하는 것이 중요!!
    sol(x, y + n / 2, n / 2);
    sol(x + n / 2, y, n / 2);
    sol(x + n / 2, y + n, n / 2);
}

int main(void){
    cin >> N;
   
    sol(0, 0, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N * 2 - 1; j++) {
            if (res[i][j] == '*')
                cout << '*';
            else
                cout << ' ';
        }
        cout << "\n";
    }
    return 0;
}

// https://www.acmicpc.net/problem/2448