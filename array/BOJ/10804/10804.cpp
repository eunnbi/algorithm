#include <iostream>
#include <algorithm>
using namespace std;


int card[21]; //  1 ≤ a ≤ b ≤ 20

int main(void) {
	
	int a, b;
	int i, j;
	for (i = 1; i <= 20; i++) { // 1-based indexing
		card[i] = i;
	}

	for (i = 0; i < 10; i++) {
		cin >> a >> b;
		if (a == b) continue;
		for (j = 0; j < (b - a + 1) / 2; j++) {
            swap(card[a + j], card[b - j]); // swap 함수 이용
		}
	}

	for (i = 1; i <= 20; i++) {
		cout << card[i] << ' ';
	}
	return 0;
}


// https://www.acmicpc.net/problem/10804