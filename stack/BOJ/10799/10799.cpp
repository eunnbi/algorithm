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
            if (s[i-1] == '(') {
                st.pop();
                res += st.size();
            }
            else {
                st.pop();
                res++;
            }
        }
    }
    cout << res << "\n";
    return 0;
}
