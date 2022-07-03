#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
	int res = 0;
	stack<char> st;

    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i]=='(') st.push(s[i]);
        else {
            if (s[i-1] == '(') { // 레이저일 경우
                st.pop(); // 앞에서 막대라고 착각하고 stack에 s[i]를 넣었으므로 pop
                res += st.size(); // 괄호의 개수만큼 res에 추가
            }
            else { // 막대의 끝일 경우
                st.pop();  // 막대의 개수를 1 감소
                res++; // 막대 1개가 절단된 것과 동일한 상황이므로 res에 1 추가
            }
        }
    }
    cout << res << "\n";
    return 0;
}

/*
문제 풀이 아이디어를 생각해내는 것은 어렵지만, 그 아이디어를 구현하는 것은 쉽다.

1. ‘)’가 등장했을 때 레이저와 막대의 끝 구분
   ⇒ 문자열에서 바로 앞 괄호가 ‘(’라면 레이저이다. 
    
2. ❗ 만약 레이저가 등장했다면 잘려나갈 막대의 수는 어떻게 구할 것인가? 
   ⇒ 스택에 쌓여 있는 괄호의 개수를 구하면 된다.
    
3. 만약 막대의 끝이라면 
   ⇒ 마지막에 잘려나갈 막대의 수 하나를 추가한다.
*/

// https://www.acmicpc.net/problem/10799