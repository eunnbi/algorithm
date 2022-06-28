#include <string.h>

int titleToNumber(char * columnTitle){
    int res = 0;
    int len = strlen(columnTitle);
    long long weight = 1;   // int 형으로 선언하면 integer overflow 발생!!! 항상 constraints 주의하기
    
    for (int i = len - 1; i >= 0; i--){
        res += (columnTitle[i] - 'A' + 1) * weight;
        weight *= 26;
    }
    return res;
}

// 26진법은 아니지만 26진법 형태로 접근 
// https://leetcode.com/problems/excel-sheet-column-number/