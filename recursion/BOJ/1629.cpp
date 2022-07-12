#include <bits/stdc++.h>
using namespace std;


long long POW(long long a, long long b, long long m){
    if (b == 1) return a % m;
    long long val = POW(a, b / 2, m); 
    val = val * val % m;
    if (b % 2 == 0) return val;
    return val * a % m;
}


int main(void){
    long long a, b, c;
    cin >> a >> b >> c;
    cout << POW(a, b, c);
    return 0;
}

// a^n * a^n = a^2n
// 1승을 계산할 수 있다. k승을 계산하면 2k승과 2k + 1을 O(1)에 계산할 수 있다.
// 마지막 한 순간에만 나머지 연산을 할 필요 없음. 중간중간에 나머지 연산해도 ok
// https://www.acmicpc.net/problem/1629