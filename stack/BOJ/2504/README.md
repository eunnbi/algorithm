# 괄호의 값

**💡 Python Tip**

`string.isdecimal()` : 특정 문자열이 decimal로 변환 가능한지 True/False 반환

**🤯 오답 코드**

런타임에 발생할 수 있는 에러를 미리 파악하자! 아래 예시로는 `int()` 와 `str()` 함수 호출 시 ValueError가 발생할 수 있다.

```python
def main():
    string = input()
    stack: list[str] = []
    for char in string:
        if (char == "(") or (char == '['):
            stack.append(char);
        else:
            partner = '(' if (char == ')') else '['
            weight = 2 if (char == ')') else 3
            if (stack):
                sum = 1 if (stack[-1] == partner) else 0
                while (stack and stack[-1] != partner):
                    if (stack[-1].isdecimal()):
                        sum += int(stack.pop())
                    else:
                        print(0)
                        return
                        
                if (stack):
                    stack.pop()
                    stack.append(str(sum * weight))
                else:
                    print(0)
                    return    
            else:
                print(0)
                return
            
    sum = 0
    while (stack):
			  sum += int(stack.pop()) # ValueError 발생
    print(sum)

if __name__ == "__main__":
    main()
```