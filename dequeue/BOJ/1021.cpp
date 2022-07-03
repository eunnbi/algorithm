#include <bits/stdc++.h>
using namespace std;

int main(void) {
	deque<int> DQ;
	int N, M;
	int res = 0;
    int num = 0;
	cin >> N >> M;
    
     // dequeue 초기화
	for (int i = 1; i <= N; i++) {
		DQ.push_back(i);
	}

	for (int i = 0; i < M; i++) {
        cin >> num;
        while (DQ.front() != num) { // 입력받은 수가 dequeue에 front에 위치해야 함!
            int idx; // dequeue에서 num이 위치한 인덱스
			int size = DQ.size();
            /*
			for (idx = 0; idx < size; idx++) {
				if (DQ[idx] == num) {
					break;
				}
			}
            */
            idx = find(DQ.begin(), DQ.end(), num) - DQ.begin(); // num이 위치한 인덱스를 찾기 위해 for문 대신 find 함수 이용
            if (idx > (size - 1) / 2) { // num이 dequeue 중앙보다 오른쪽에 위치
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            else { // num이 dequeue 중앙보다 왼쪽에 위치
                DQ.push_back(DQ.front());
				DQ.pop_front();
            }
            res++;
        }
        DQ.pop_front();
	}
	cout << res;
	return 0;
}

/*
💡 deque는 vector와 비슷하지만 데이터를 앞뒤로 삽입하거나 삭제하고 싶을 때 사용된다.

❗ find 함수
- algorithm 헤더파일에 있는 함수
- vector 혹은 deque 내에 해당 원소가 존재하는지 혹은 인덱스를 찾을 때 사용한다.
- find(v.begin(), v.end(), 찾을 대상)
    - return 값 == v.end(): 해당 원소가 존재하지 않는 것
    - return 값 != v.end(): 해당 원소가 존재하는 것
- find(v.begin(), v.end(), 찾을 대상) - v.begin()
    - vector 혹은 deque 내에서 해당 원소가 위치하는 인덱스 찾기
*/

// https://www.acmicpc.net/problem/1021