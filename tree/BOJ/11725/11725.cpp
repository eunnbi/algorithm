#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int p[100001];

void dfs(int cur) {
	for (int nxt : adj[cur]) {
		if (p[cur] == nxt) continue;
		p[nxt] = cur;
		dfs(nxt);
	}
}

int main(void) {
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << p[i] << '\n';
	}
	return 0;
}