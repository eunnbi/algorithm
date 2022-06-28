#include <string.h>

int count = 0;
char str[11];
int used[11];
int perm(int n, int k, int i){
    if (i == n){  // permutation이 하나 왼성되었다는 뜻
        count++; 
        if (k == count) return 1;
        return 0;
    }
    for (int j = 1; j <= n; j++){
        if (used[j]) continue; // 중복 사용 금지
        used[j] = 1;
        str[i] = j + '0';
        int ret = perm(n, k, i + 1);
        if (ret) return 1;
        used[j] = 0;
    }
    return 0;
}
char * getPermutation(int n, int k){
    for (int i = 1; i <= n; i++) used[i] = 0;
    count = 0;
    perm(n, k, 0);
    str[n] = 0;
    return str;
}

/*
🙌 Approach

How to generate permutations?
- This is similar to generating all strings of length N using N digits
- The difference is that we cannot use the same digit more than once
- We need to check whether each digit has been used or not

"str" = permutation sequence that we are generating
"count" = the number of permutation sequences generated so far
"used[i]" = 1 if digit i has been used in str, otherwise 0
"perm(n, k, i)" : filling str[i]. it return 1 we found the answer
⇒ we put every possible digit to str[i] and move on to perm(n, k, i + 1)
*/

// https://leetcode.com/problems/permutation-sequence/