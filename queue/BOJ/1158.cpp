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
💡 하나의 문제는 여러 자료구조 형태로 해결할 수 있다!!
- 원형 연결리스트로도 문제를 풀 수 있지만, 큐를 이용해도 문제 해결이 가능하다.
*/

// https://www.acmicpc.net/problem/1158