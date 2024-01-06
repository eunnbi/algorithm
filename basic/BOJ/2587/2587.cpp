#include <iostream>
#include <algorithm>

using namespace std;

int num[5], total;

int main(void) {
    
  for(int i = 0; i < 5; i++) cin >> num[i];
    
  // 평균
  for(int i = 0; i < 5; i++) total += num[i];
  cout << total / 5 << "\n";
    
  // 중앙값
  sort(num, num + 5);
  cout << num[2];
}

/*
👉 sort 함수
- algorithm 헤더 파일에 포함되어 있음.
- 기본적으로 오름차순 정렬을 수행한다.
- sort(배열의 시작 주소, 배열의 마지막 주소  + 1)
- compare 함수를 만들어 sort()의 세 번째 인자 값으로 넣게 되면, 해당 함수의 반환 값에 맞게 정렬이 동작한다.
- 참고 : https://m.blog.naver.com/ndb796/221227975229
*/

// compare 함수
bool compare(int a, int b){
	return a > b;
}

int main(void){
	int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
	int b[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
	sort(a, a + 10);  // 오름차순
	sort(b, b + 10, compare);  // 내렴차순
}

// https://www.acmicpc.net/problem/2587