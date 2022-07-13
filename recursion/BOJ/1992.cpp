#include <bits/stdc++.h>
using namespace std;

int N;
string paper[65];
string res;

bool check(int x, int y, int z){
    for (int i = x; i < x + z; i++){
        for (int j = y; j < y + z; j++){
            if (paper[x][y] != paper[i][j]){
                return false;
            }
        }
    }
    return true;
}

void sol(int x, int y, int n){
    if (check(x, y, n)){
        res += paper[x][y];
        return;
    }
    res += "(";
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            sol(x + i * n / 2, y + j * n / 2, n / 2);
        }
    }
    res += ")";
}


int main(void){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> paper[i];
    }
    sol(0, 0, N);
    cout << res;
    return 0;
}