#include <bits/stdc++.h>
using namespace std;


int main(void) {
    int N, K;
    cin >> N >> K;
    int remain = N;

    queue<int> Q;
    for (int i = 1; i <= N; i++) Q.push(i);

    cout << "<";
    while (Q.size() > 1){
        for (int i = 0; i < K - 1; i++){
            int num = Q.front();
            Q.push(Q.front());
            Q.pop();
        }
        cout << Q.front() << ", ";
        Q.pop();
    }
    cout << Q.front() << ">";
    return 0;
}
/*
π‘ νλμ λ¬Έμ λ μ¬λ¬ μλ£κ΅¬μ‘° ννλ‘ ν΄κ²°ν  μ μλ€!!
- μν μ°κ²°λ¦¬μ€νΈλ‘λ λ¬Έμ λ₯Ό ν μ μμ§λ§, νλ₯Ό μ΄μ©ν΄λ λ¬Έμ  ν΄κ²°μ΄ κ°λ₯νλ€.
*/

// https://www.acmicpc.net/problem/1158