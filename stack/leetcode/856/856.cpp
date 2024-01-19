#include <string.h>
#include <stack>
#include <string>

using namespace std;

// 1. using stack with array
int st[51], top;
int scoreOfParentheses(char * s){
    top = 0;
    int len = strlen(s);
    int sum;
    for (int i = 0; i < len; i++){
        if (s[i] == '(') st[top++] = -1;
        else if (st[top - 1] == -1) st[top - 1] = 1;
        else {
            sum = 0;
            while (st[--top] != -1) {
                sum += st[top];
            }
            st[top++] = sum * 2;
        }
    }
    sum = 0;
    while (--top >= 0) sum += st[top];
    return sum;
}


// 2. STL stack
int scoreOfParentheses(string s) {
    stack<int> st;
    int len = s.length();
    int sum = 0;
    for (int i = 0; i < len; i++){
        if (s[i] == '(') st.push(-1);
        else if (st.top() == -1) {
            st.pop();
            st.push(1);
        }
        else {
            sum = 0;
            while (st.top() != -1){
                sum += st.top();
                st.pop();
            }
            st.pop();
            st.push(sum * 2);
        }
    }
    sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }
    return sum;
}

// https://leetcode.com/problems/score-of-parentheses/