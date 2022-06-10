// Permutation Sequence

char res[11];
int used[11];
int cnt;
int sol(int n, int k, int i){
    if (i == n) {
        cnt++;
        if (cnt == k) return 1;
        else return 0;
    }
    
    for (int j = 1; j <= n; j++){
        if (used[j]) continue;
        used[j] = 1;
        res[i] = j + '0';
        int ret = sol(n, k, i + 1);
        used[j] = 0;
        if (ret) return 1;
    }
    return 0;
}

char * getPermutation(int n, int k){
    memset(used, 0, sizeof(used));
    cnt = 0;
    sol(n, k, 0);
    res[n] = '\0';
    return res;
}