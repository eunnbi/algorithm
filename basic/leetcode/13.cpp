#include <string.h>

int charToInt(char c){
    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char * s){
    int res = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        int cur = charToInt(s[i]);
        if (i == len - 1) res += cur;
        else {
            if (cur >= charToInt(s[i + 1])) res += cur;
            else res -= cur;
        }        
    }
    return res;
}

// 현재 문자가 다음 문자보다 정수값이 크거나 같다면 더하고, 작다면 뺀다
// https://leetcode.com/problems/roman-to-integer/