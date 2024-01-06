# 세수 정렬

## For Python

📌 **정렬**

숫자 문자열로 이루어진 배열을 정렬한다면 문자열은 사전 순으로 나열하므로 숫자 배열을 정렬한 것과 다른 결과를 도출할 수 있다.

Ex) `[’10’, ‘1’, ‘5’]` → `[’1’, ‘10’, ‘5’]`

🤯 **오답 코드**

```python
def main():
    str = input()
    list = str.split(' ') 
    list.sort()
    seperator = ' '
    print(seperator.join(list))

if __name__ == "__main__":
    main()
```

문자열은 사전 순대로 정렬된다.

## For Cpp

👉 **min, max 함수**
- algorithm 헤더 파일에 구현되어 있는 함수이다.
- {}을 이용하여 3개 이상의 값들에 대해 최소값, 최대값을 구할 수 있다.

👉 **minmax 함수**
- `pair<int, int>` 타입 반환
- first에는 최소값, second에는 최대값이 들어가 있다.
