#include <bits/stdc++.h>
using namespace std;

string s;
stack<int> st;
int main(void) {
    cin >> s;
    int len = s.length();
    int sum = 0;

    for (int i = 0; i < len; i++){
        if (s[i] == '(') st.push(-1);
        else if  (s[i] == '[')  st.push(-2);
        else if (s[i] == ')'){
            if (st.empty()) {
                cout << 0;
                return 0;
            }
            if (st.top() == -1) {
                st.pop(); 
                st.push(2);
            }
            else {
                sum = 0;
                while (!st.empty() && st.top() != -1) {
                    if (st.top() < 0) {
                        cout << 0;
                        return 0;
                    }
                    sum += st.top();
                    st.pop();
                }
                if (st.empty()) {
                    cout << 0;
                    return 0;
                }
                st.pop();
                st.push(sum * 2);
            }
        }
        else if (s[i] == ']') {
            if (st.empty()) {
                cout << 0;
                return 0;
            }
            if (st.top() == -2) {
                st.pop();
                st.push(3);
            }
            else {
                sum = 0;
                while (!st.empty() && st.top() != -2) {
                    if (st.top() < 0) {
                        cout << 0;
                        return 0;
                    }
                    sum += st.top();
                    st.pop();
                }
                if (st.empty()) {
                    cout << 0;
                    return 0;
                }
                st.pop();
                st.push(sum * 3);
            }
        }
    }
    sum = 0;
    while (!st.empty()) {
        if (st.top() < 0) {
            cout << 0;
            return 0;
        }
        sum += st.top();
        st.pop();
    }
    cout << sum;
    return 0;
}

// leetcode 856 문제 풀이 응용 (올바르지 않은 괄호쌍 체크하는 분기 추가)
// https://www.acmicpc.net/problem/2504