// N-Queens 2

int col[10];
int d1[20];
int d2[20];
int cnt;
void sol(int n, int i){
    if (i == n) {
        cnt++;
        return;
    }
    
    for (int j = 0; j < n; j++){
        if (col[j] || d1[i + j] || d2[i - j + n]) continue;
        col[j] = d1[i + j] = d2[i - j + n] = 1;
        sol(n, i + 1);
        col[j] = d1[i + j] = d2[i - j + n] = 0;
    }
}

int totalNQueens(int n){
    cnt = 0;
    sol(n, 0);
    return cnt;
}