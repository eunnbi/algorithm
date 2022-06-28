#include <string.h>

int stack[51], top;
int scoreOfParentheses(char * s){
    top = 0;
    int len = strlen(s);
    int sum;
    for (int i = 0; i < len; i++){
        if (s[i] == '(') stack[top++] = -1;
        else if (stack[top - 1] == -1) stack[top - 1] = 1;
        else {
            sum = 0;
            while (stack[--top] != -1) {
                sum += stack[top];
            }
            stack[top++] = sum * 2;
        }
    }
    sum = 0;
    while (--top >= 0) sum += stack[top];
    return sum;
}

// https://leetcode.com/problems/score-of-parentheses/