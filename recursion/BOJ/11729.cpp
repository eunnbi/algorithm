#include <bits/stdc++.h>
using namespace std;


void hanoi(int n, int from, int via, int to){
    if (n == 1) {
        cout << from << ' ' << to << '\n';
        return; // return문 필수!!!
    }
    hanoi(n-1, from , to , via);
    cout << from << ' ' << to << '\n';
    hanoi(n - 1, via, from, to); 
}

int main(void){
    int N;
    cin >> N;
    cout << (1 << N) - 1 << '\n'; // 공식!!
    hanoi(N, 1, 2, 3);
    return 0;
}


// https://www.acmicpc.net/problem/11729