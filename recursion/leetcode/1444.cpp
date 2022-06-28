#include <string.h>

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

// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
