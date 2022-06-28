#include <string.h>

// 1.
#define MOD 1000000007
int n, m;
char **pizza;
long long memo[51][51][11]; // Memoization

// each piece contains at least one apple.
int contain(int row_start, int row_end, int column_start, int column_end){
	for (int i = row_start; i < row_end; i++){
		for (int j = column_start; j < column_end; j++){
			if (pizza[i][j] == 'A') return 1;
		}
	}
	return 0;
}

long long cut(int row, int column, int k){
	if (memo[row][column][k] != -1) return memo[row][column][k];
	if (k == 1) return contain(row, n, column, m); // each piece contains at least one apple. 

	long long res = 0; // the number of ways of cutting pizza[row:N][column:M] into k pieces.

	// row cutting
	for (int i = row + 1; i < n; i++){
		if (contain(row, i, column, m)){
			res += cut(i, column, k - 1);
		} 
	}

	// column cutting
	for (int i = column + 1; i < m; i++){
		if (contain(row, n, column, i)){
			res += cut(row, i, k - 1);
		}
	}
	return memo[row][column][k] = res;
}

int ways(char ** _pizza, int pizzaSize, int k){
	memset(memo, -1, sizeof(memo));
	n = pizzaSize;
   	m = strlen(_pizza[0]);
	pizza = _pizza;
	return cut(0, 0, k) % MOD;
}

/*
💖 Approach
- "Exhaustive Search" : For each cut, test all possibilities + Memoization
- "cut(row, column, k)" = the number of ways of cutting pizza[row:N][column:M] into k pieces.
*/

// 2.
// 피자 조각이 하나 이상의 사과를 포함하는지 확인하는 부분을 최적화하기 위해 "2D-array prefix sum" 이용하기
// 즉, 앞선 코드에서 'contain' 함수의 역할을 최적화
#define MOD 1000000007
int n, m;
int prefix[52][52];
long long memo[51][51][11]; // Memoization

long long cut(int row, int column, int k, int total){
	if (memo[row][column][k] >= 0) return memo[row][column][k];
	if (k == 1) return 1;

	long long res = 0; // the number of ways of cutting pizza[row:N][column:M] into k pieces.

	// row cutting
	for (int i = row + 1; i < n; i++){
		int rest = prefix[n][m] - prefix[i][m] - prefix[n][column] + prefix[i][column];
		int piece = total - rest;
		if (rest > 0 && piece > 0){
			res += cut(i, column, k - 1, rest);
		} 
	}

	// column cutting
	for (int i = column + 1; i < m; i++){
		int rest = prefix[n][m] - prefix[n][i] - prefix[row][m] + prefix[row][i];
		int piece = total - rest;
		if (rest > 0 && piece > 0){
			res += cut(row, i, k - 1, rest);
		} 
	}
	return memo[row][column][k] = res;
}

int ways(char ** pizza, int pizzaSize, int k){
	memset(memo, -1, sizeof(memo));
	memset(prefix, 0, sizeof(prefix));
	n = pizzaSize;
    m = strlen(pizza[0]);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
			if (pizza[i - 1][j - 1] == 'A') prefix[i][j] += 1;
		}
	}
	int total = prefix[n][m];
	return cut(0, 0, k, total) % MOD;
}

// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
