# 잃어버린 괄호 🥈

```cpp
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
```

👉 관찰 결과, '+' 연산자 우선순위가 '-'보다 높다고 간주하여 수식을 계산하는 것이 항상 식의 값을 최소로 만든다.

1. 입력받은 문자열 파싱
2. 후위표기식으로 변환. 이때, '-'보다 '+'의 연산자 우선순위가 높다.
3. 후위표기식 계산하고 결과값 출력

> 후위표기식 변환 및 계산할 때 `stack` 자료 구조를 이용했다.
>
> ✔️ 중위 표기법을 후위 표기법으로 바꾸기
>
> 1. 피연산자가 들어오면 바로 출력
> 2. 연산자가 들어오면 자기보다 우선 순위가 높거나 같은 것들을 빼고 자신을 스택에 담기
> 3. 여는 괄호를 만나면 무조건 스택에 담기
> 4. 닫는 괄호를 만나면 (를 만날 때까지 스택에서 연산자를 빼고 출력
>
> ✔️ 후위 표기법을 계산하는 방법
>
> 1.  피연산자가 들어오면 스택에 담기
> 2.  연산자를 만나면 스택에서 두 개의 피연산자를 꺼내서 연산한 뒤에 그 결과를 스택에 담기
> 3.  연산을 마친 뒤에 스택에 남아있는 하나의 피연산자가 연산 수행 결과
