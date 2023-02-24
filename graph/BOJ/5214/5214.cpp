#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> hypertube[1002];
vector<int> station[100002];
int dist[100002];
int main() {
    int n, k, m, num;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> num;
            station[num].push_back(i);
            hypertube[i].push_back(num);
        }
    }
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == n) {
            cout << dist[n];
            return 0;
        }
        for (int tube: station[cur]) {
            for (int nxt: hypertube[tube]) {
               if (dist[nxt] != 0) continue;
                dist[nxt] = dist[cur] + 1;
                q.push(nxt); 
            }
        }
    }
    cout << -1;
    return 0;
}