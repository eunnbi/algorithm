# 일곱 난쟁이

📌 **중첩 반복문 흐름 제어**

중첩 반목문을 사용했을 때, 어느 반복문에서 `break`, `continue` 을 사용했는지, 정확히 파악해야 한다. 바깥 반복문에서도 `break`를 사용해야 하는 경우가 있는데 이를 빼먹어서 틀리는 경우가 종종 발생한다.

🤯 **오답 코드**

```python
def main():
    list = []
    sum = 0
    for i in range(9):
        num = int(input())
        sum += num
        list.append(num)
    list.sort()
    x = sum - 100
    for i in range(len(list)):
        for j in range(0, i):
            if (list[i] + list[j] == x):
                list.remove(list[i])
                list.remove(list[j])
                break
		# 이 반복문에서도 break 해야 함!!
    for num in list:
        print(num)

if __name__ == "__main__":
    main()
```
안쪽 반복문뿐만 아니라 바깥 반복문에서도 `break` 해야 한다.