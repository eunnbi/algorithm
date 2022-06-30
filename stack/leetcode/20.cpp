#include <string.h>
#include <stack>
#include <string>

using namespace std;

// 1. using stack with array
char st[10000]; // stack
int top;
bool isValid(char * s){
    top = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            st[top++] = s[i];
        }
        else {
            top--;
            if (top < 0) return false; // stack이 비어있다면
            if (s[i] == ')' && st[top] != '(') return false;
            if (s[i] == ']' && st[top] != '[') return false;
            if (s[i] == '}' && st[top] != '{') return false;
        }
    }
    if (top != 0) return false; // stack이 비어 있지 않다면
    else return true;
}

// 2. STL Stack
bool isValid(string s){
    stack<char> st;
    int len = s.length();
    for (int i = 0; i < len; i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }
        else {
            if (st.empty()) return false; // stack이 비어있다면
            if (s[i] == ')' && st.top() != '(') return false;
            if (s[i] == ']' && st.top() != '[') return false;
            if (s[i] == '}' && st.top() != '{') return false;
            st.pop();
        }
    }
    if (!st.empty()) return false; // stack이 비어 있지 않다면
    else return true;
}

// Why Stack?? : LIFO => 가장 최근 데이터를 가장 먼저 참조할 수 있다.
// https://leetcode.com/problems/valid-parentheses/

