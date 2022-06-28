#include <string.h>
#include <stdlib.h>

char * removeKdigits(char * num, int k){
    int len = strlen(num);
    int nonZero = 0;
    for (int i = 0; i < len; i++) {
        if (num[i] != '0') nonZero++;
    }
    if (nonZero <= k) return "0"; // 반드시 큰 따옴표!!
    
    char * res = (char*)malloc(sizeof(char) * len);
    res[0] = num[0];
    int index = 0;
    int resLen = len - k;
    
    // 핵심
    for (int i = 1; i < len; i++){
        while (index >= 0 && res[index] > num[i] && k){
            index--;
            k--;
        }
        res[++index] = num[i];
    }
    res[resLen] = '\0';
    for (; *res == '0'; res++);  // leading zeros 지우기
    return res;
}


/*
앞자리의 수가 작으면 작을수록 전체 수가 작아진다.
즉, 주어진 문자열의 문자와 정답 문자열에 있는 문자를 뒤에서부터 비교하여 주어진 문자가 작을 동안 앞으로 당겨서 덮어쓰기
=> It is always better to place smaller digits to the front regardless of how many chances it costs (Greedy Approach)
이때, # of non-zero numbers ≤ k : 모든 0이 아닌 수를 지울 수 있으므로 “0”을 리턴한다.
*/

// https://leetcode.com/problems/remove-k-digits/