#include <stdio.h>

int N;
char res[6565][6565];
void sol(int x, int y, int n){
    if (n == 1) {
        res[x][y] = '*';
        return;
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == 1 && j == 1) continue;
            sol(x + i * n / 3, y + j * n / 3, n / 3);
        }
    }
}

int main(void){
    scanf("%d", &N);

    // 🙌 초기화 필수!!
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            res[i][j] = ' ';
        }
    }
    sol(0, 0, N);
    for (int i = 0; i < N; i++){
        printf("%s", res[i]);
        printf("\n");
    }
    return 0;
}

// https://www.acmicpc.net/problem/2447