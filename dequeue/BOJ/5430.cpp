#include <bits/stdc++.h>
using namespace std;

// 1. 시간 초과 발생

// 👉 문자열 파싱!!
void parse(string& temp, deque<int>& d) {
	int cur = 0; 
	int len = temp.length();
	for (int i = 1; i < len - 1; i++) {
		if (temp[i] == ',') {
			d.push_back(cur);
			cur = 0;
		}
		else {
			cur = 10 * cur + (temp[i] - '0');
		}
	}
	if (cur != 0) {
		d.push_back(cur);
	}
}

int main(void){
    int T;
    string p, temp;
    int n;
    cin >> T;
    while (T--){
        deque<int> DQ;
        cin >> p;
        cin >> n;
        cin >> temp;
        parse(temp, DQ);

        bool isError = false;
        for (char c : p){
            if (c == 'D'){
                if (DQ.empty()){
                    cout << "error\n";
                    isError = true;
                    break;
                }
                DQ.pop_front();
            }
            else {
                reverse(DQ.begin(), DQ.end()); // 여기에서 시간초과가 발생하는 것 같다.
            }
        }
        if (!isError) {
            int size = DQ.size();
            cout << '[';
            for (int i = 0; i <size; i++){
                cout << DQ[i];
                if (i != size - 1) cout << ',';
            }
            cout << "]\n";

        }
    }

    return 0;
}


// 2. 시간 초과 안 나는 코드 (flag 이용)
int main(void){
    int T;
    string p, temp;
    int n;
    cin >> T;
    while (T--){
        deque<int> DQ;
        cin >> p;
        cin >> n;
        cin >> temp;
        parse(temp, DQ);

        bool isError = false;
        int rev = 0;
        for (char c : p){
            if (c == 'D'){
                if (DQ.empty()){
                    cout << "error\n";
                    isError = true;
                    break;
                }
                if (rev) DQ.pop_back(); // reverse된 상태라면 마지막 원소 제거
                else DQ.pop_front();
            } 
            else rev = 1 - rev; // flag 변경
        }
        if (!isError) {
            // 마지막에 출력할 때 reverse 함수 적용
            if (rev) reverse(DQ.begin(), DQ.end());
            int size = DQ.size();
            cout << '[';
            for (int i = 0; i <size; i++){
                cout << DQ[i];
                if (i != size - 1) cout << ',';
            }
            cout << "]\n";
        }
    }

    return 0;
}
/*
💡 deque는 vector와 비슷하지만 vector와 다르게 원소를 맨 앞에 삽입하거나 맨 앞의 원소를 삭제할 수 있다.

❗ reverse 함수
- algorithm 헤더파일에 있는 함수이다.
- reverse(시작 반복자, 종료 반복자)
*/

// https://www.acmicpc.net/problem/5430