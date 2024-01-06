# 두 수의 합

**📌 Out of Bounds 주의**

배열 인덱싱하거나 배열의 크기를 미리 정해야 할 때 bound 파악!!

🤯 **오답 코드**

```python
def main():
    n = int(input())
    nums = [0] * 1000002 # Out of bounds 발생!!
    str = input()
    temp = str.split(' ')
    list = [int(i) for i in temp]
    for num in list:
        nums[num] += 1
    x = int(input())
    res = 0
    for num in list:
        if (x > num):
            res += nums[x - num]
    print(int(res / 2))

if __name__ == "__main__":
    main()
```
`x` 최대값이 2,000,000이고, `num` 최소값이 1이기 때문에, `nums` 배열 인덱스의 최대값은 1,999,999 여야 한다.