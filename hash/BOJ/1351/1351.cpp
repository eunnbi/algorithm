#include <iostream>
#include <unordered_map>
using namespace std;

long long n, p, q;
unordered_map<long long, long long> a;
long long solve(long long num) {
    if (num == 0) return 1;
    else if (a[num] != 0) return a[num];
    return a[num] = solve(num / p) + solve(num / q);
}

int main() {
    cin >> n >> p >> q;
    cout << solve(n);
    return 0;
}