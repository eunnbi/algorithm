
#include <string.h>

int check[128]; // ASCII code 개수만큼 배열의 길이 선언
int lengthOfLongestSubstring(char * s){

    for (int i = 0; i < 128; i++) check[i] = 0; // 배열 초기화

    int res = 0;
    int len = strlen(s);
    int left = 0; // left, right -> two pointer
    for (int right = 0; right < len; right++){
        while (check[(int) s[right]] && left < right) check[(int)s [left++]]--;
        check[(int) s[right]]++;
        if ((right - left + 1) > res) res = right - left + 1;
    }
    
    return res;
}

/*
🌻 Approach
1. substring → "two pointer" 이용
2. 문자가 중복된다는 것을 어떻게 알 수 있나? → "check" 배열 이용
3. 전체적인 알고리즘
    - 현재 right가 가리키고 있는 문자가 이미 등장한 문자라면 중복이 없어질 때까지 left를 1씩 증가하며 check 배열 기록 취소
    - right가 가리키고 있는 문자 check 배열에 기록
    - substring 길이가 최대라면 저장
*/
// https://leetcode.com/problems/longest-substring-without-repeating-characters/