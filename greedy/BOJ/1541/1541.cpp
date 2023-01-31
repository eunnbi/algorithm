#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#define PLUS -1
#define MINUS - 2
using namespace std;

string s;
vector<int> exp;
deque<int> num;
stack<int> st;
int main() {
    cin >> s;

    // 1. 문자열 파싱
    int size = s.size();
    int temp = 0;
    int w = 1;
    for (int i = size - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            temp += (s[i] - '0') * w;
            w *= 10; 
        }
        else {
            num.push_front(temp);
            temp = 0;
            w = 1;
            num.push_front(s[i] == '-' ? MINUS : PLUS);
        }
    }
    if (temp) {
        num.push_front(temp);
        temp = 0;
        w = 1;
    }

    // 2. 후위 표기식으로 변환. 이때, -보다 +의 우선순위가 높음 (greedy)
    for (int a : num) {
        if (a == PLUS || a == MINUS) {
            while (!st.empty() && a <= st.top()) {
                exp.push_back(st.top());
                st.pop();
            }
            st.push(a);
        }
        else {
            exp.push_back(a);
        }
        
    }
    while (!st.empty()) {
        exp.push_back(st.top());
        st.pop();
    }

    // 3. 후위표기식 계산하기
    for (int a : exp) {
        if (a == PLUS || a == MINUS) {
            int right = st.top(); st.pop();
            int left = st.top(); st.pop();
            if (a == PLUS) {
                st.push(left + right);
            }
            else {
                st.push(left - right);
            }
        }
        else {
            st.push(a);
        }
    }

    // 4. 정답 출력
    cout << st.top() << '\n';
    return 0;
}