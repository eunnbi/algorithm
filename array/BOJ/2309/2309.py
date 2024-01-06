list = []

def sol(x: int):
    for i in range(0, len(list)):
        for j in range(0, i):
            if (list[i] + list[j] == x):
                list.remove(list[i])
                list.remove(list[j])
                return

def main():
    sum = 0
    for _ in range(9):
        num = int(input())
        sum += num
        list.append(num)
    list.sort()
    sol(sum - 100)           
    for num in list:
        print(num)

if __name__ == "__main__":
    main()