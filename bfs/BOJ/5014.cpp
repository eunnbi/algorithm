#include <bits/stdc++.h>
using namespace std;

int dist[1000001];

int main(void){
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    memset(dist, -1, sizeof(dist));
    queue<int> Q;
    Q.push(s);
    dist[s] = 0;
    while (!Q.empty()){
        int cur = Q.front(); Q.pop();
        int up = cur + u;
        int down = cur - d;
        if (up >= 1 && up <= f && dist[up] < 0){
            dist[up] = dist[cur] + 1;
            Q.push(up);
        }
        if (down >= 1 && down <= f && dist[down] < 0){
            dist[down] = dist[cur] + 1;
            Q.push(down);
        }
    }
    if (dist[g] == -1) cout << "use the stairs";
    else cout << dist[g];
    return 0;
}

// https://www.acmicpc.net/problem/5014