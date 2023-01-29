# Basic

## Time Complexity

| N의 크기      | 허용 시간복잡도 |
| ------------- | --------------- |
| N ≤ 11        | O(N!)           |
| N ≤ 25        | O(2^N)          |
| N ≤ 100       | O(N^4)          |
| N ≤ 500       | O(N^3)          |
| N ≤ 3000      | O(N^2logN)      |
| N ≤ 5000      | O(N^2)          |
| N ≤ 1,000,000 | O(NlogN)        |
| N≤ 10,000,000 | O(N)            |
| 그 이상       | O(logN), O(1)   |

🚀 **Remember that `10,000 * 10,000` takes about one second.**

<br/>

## Space Complexity

- 512MB = 1.2억 개의 int 형
- 사이즈가 큰 변수는 전역 변수로 선언

<br/>

## Data Type

**char, short, int**

|          | char형        | short형      | int형           |
| -------- | ------------- | ------------ | --------------- |
| byte     | 1byte (=8bit) | 2byte        | 4byte           |
| unsigned | 0 ~ 255       | 0 ~ 65,535   | 0~약 42억       |
| signed   | -128 ~ 127    | -32768~32767 | 약 -21억 ~ 21억 |

🚀 **`Integer Overflow` 주의!** Integer overflow가 발생하면 `int`형 대신 `long long` 형으로 선언

<br/>

**float, double**

- 실수의 저장 및 연산 과정에서 오차가 발생할 수 있다.
  - 가수부의 bit 수 제한 → 유효 자릿수 존재
- double에 long long 범위의 정수를 함부로 담으면 안된다.
  - 가수부의 bit 수 제한 때문이다.
- 실수를 비교할 때 등호를 사용해선 안된다. 등호 대신 부등호를 이용한다.
  - abs(a-b) < 1e-12 → a와 b는 동일한 값으로 판단

<br/>

## Function Call

1. `call by value`
   - argument의 상수값을 복사하여 전달
   - 원본 데이터 변경 불가능
2. `call by reference`
   - argument의 시작주소 전달
   - 함수 내부에서 원본 수정 가능

<br/>

## STL and Function call

- STL를 함수 인자에 넣으면 복사되어 전달된다. => `call by value`
- 복사본을 만드는데 비용이 발생한다.

  ```cpp
  // O(N)
  bool cmp1(vector<int> v1, vector<int> v2, int idx){
      return v1[idx] > v2[idx];
  }

  // O(1)
  bool cmp1(vector<int>& v1, vector<int>& v2, int idx){
      return v1[idx] > v2[idx];
  }
  ```

<br/>

> 💡 코딩테스트의 목표는 남이 알아볼 수 있는 클린코드를 작성하는 것이 아니다. 어떻게든 제한된 시간 안에 정답을 받아야 한다!
