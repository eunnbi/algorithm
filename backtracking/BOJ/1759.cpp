#include <bits/stdc++.h>
using namespace std;

int L, C;
int eng[20];
int res[20];

bool isVowels(char ch){
    if (ch == 'a'){
        return true;
    }
    else if (ch == 'e'){
        return true;
    }
    else if (ch == 'i'){
        return true;
    }
    else if (ch == 'o'){
        return true;
    }
    else if (ch == 'u'){
        return true;
    }
    else {
        return false;
    }
}

// sum1: 자음 개수, sum2: 모음 개수
void sol(int i, int sum1, int sum2){
    if (i == L) {
        if (sum1 < 2 || sum2 < 1) return;
        for (int j = 0; j < L; j++){
            printf("%c", eng[res[j]] + 'a');
        }
        printf("\n");
        return;
    }

    int prev = i > 0 ? res[i - 1] + 1 : 0;
    for (int j = prev; j < C; j++){
        res[i] = j;
        if (isVowels(eng[j] + 'a')) {
            sol(i + 1, sum1, sum2 + 1);
        }
        else {
            sol(i + 1, sum1 + 1, sum2);
        }
    }
}

int main(void){
    cin >> L >> C;
    for (int i = 0; i < C; i++){
        char ch;
        cin >> ch;
        eng[i] = ch - 'a';
    }
    sort(eng, eng + C);
    sol(0, 0, 0);
    return 0;
}