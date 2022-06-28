#include <stdlib.h>

int **res, num_comb = 0;
int comb[30];

int nck(int n, int k){
    if (k == 0 || n == k) return 1;
    return nck(n - 1, k) + nck(n - 1, k - 1);
}

void choose(int n, int k, int i){
    if (i == k){
        for (int j = 0; j < k; j++){
            res[num_comb][j] = comb[j];
        }
        num_comb++;
        return; // return문 반드시 있어야 함!!
    }
    int prev = i > 0 ? comb[i - 1] : 0;
    for (int j = prev + 1; j <= n; j++){
        comb[i] = j;
        choose(n, k, i + 1);
    }
    
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    int row = nck(n, k); // 2d array 세로 길이
    *returnSize = row;
    *returnColumnSizes = (int*)malloc(sizeof(int) * row);
    for (int i = 0; i < row; i++){
        (*returnColumnSizes)[i] = k;
    }
    
    res = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++){
        res[i] = (int*)malloc(sizeof(int) * k);
    }

    num_comb = 0;
    choose(n, k, 0);
    
    return res;
}

/*
🚀 Approach

This problem is similar to the "permutation sequence" problem except that
- We generate strings of length 'k' using 'n' digits
- The order of digits must be ignored
    - [1, 2] == [2, 1]
    - This is little bit tricky.
    - We will only generate sequences whose elements are in increasing order
        - Because there is only one ordering where N unique numbers increase, it is guaranteed that all duplicates will be removed
        - [1, 2, 3] - counted
        - [3, 2, 1] - not counted
        - [2, 1, 3] - not counted
*/

// https://leetcode.com/problems/combinations/