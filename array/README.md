# 배열

## 배열이란?

동일한 데이터 형의 자료를 메모리 상에서 연속하게 배치한 자료구조이다.

## 성질

- `O(1)`에 k번째 원소를 확인 및 변경 가능
- 추가적으로 소모되는 메모리의 양 (= `overhead`)가 거의 없음
- `Cache hit rate`가 높음
- 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸림

## 기능

| 기능                                   | 시간복잡도 |
| -------------------------------------- | ---------- |
| 임의의 위치에 있는 원소를 확인 및 변경 | `O(1)`     |
| 원소를 배열의 끝에 추가                | `O(1)`     |
| 마지막 원소 제거                       | `O(1)`     |
| 임의의 위치에 있는 원소 추가           | `O(N)`     |
| 임의의 위치에 있는 원소 제거           | `O(N)`     |
