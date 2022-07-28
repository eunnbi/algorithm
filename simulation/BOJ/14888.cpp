#include <bits/stdc++.h>
#define PLUS 0
#define SUB 1
#define MUL 2
#define DIV 3
using namespace std;

int N;
int num[12];
int op[4];
int brute[12];
// 최대, 최소 초기화!!
int mx = -0x7f7f7f7f; 
int mn = 0x7f7f7f7f;

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
	for (int i = 0; i < 4; i++) cin >> op[i];

	int start = 0;
	int last = op[0];
	for (int i = 0; i < 4; i++) {
		fill(brute + start, brute + last, i);
		if (i != 3) {
			start += op[i];
			last += op[i + 1];
		}
	}

	do {
		int res = num[0];
		for (int i = 0; i < N - 1; i++) {
			if (brute[i] == PLUS) {
				res += num[i + 1];
			}
			else if (brute[i] == SUB) {
				res -= num[i + 1];
			}
			else if (brute[i] == MUL) {
				res *= num[i + 1];
			}
			else if (brute[i] == DIV) {
				if (res < 0) {
					int tmp = -res;
					tmp /= num[i + 1];
					res = -tmp;
				}
				else {
					res /= num[i + 1];
				}
			}
		}
		if (res > mx) mx = res;
		if (res < mn) mn = res;

	} while (next_permutation(brute, brute + N - 1));

	printf("%d\n", mx);
	printf("%d\n", mn);
	return 0;
}