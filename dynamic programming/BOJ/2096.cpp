#include <bits/stdc++.h>
using namespace std;

int N;
int colMax[3];
int colMin[3];
int tempMax[3];
int tempMin[3];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> tempMax[j];
			tempMin[j] = tempMax[j];
			tempMax[j] += max(colMax[1], (j == 1) ? max(colMax[0], colMax[2]) : colMax[j]);
			tempMin[j] += min(colMin[1], (j == 1) ? min(colMin[0], colMin[2]) : colMin[j]);
		}
		memcpy(colMax, tempMax, sizeof(int) * 3);
		memcpy(colMin, tempMin, sizeof(int) * 3);
	}
	sort(colMax, colMax + 3);
	sort(colMin, colMin + 3);
	cout << colMax[2] << ' ' << colMin[0] << '\n';
	return 0;
}