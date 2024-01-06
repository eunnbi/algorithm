def main():
    sum = 0
    odds = []
    for i in range(7):
        num = int(input())
        if (num % 2 == 1):
            sum += num
            odds.append(num)
    if (sum == 0):
        print(-1)
    else:
        print(sum)
        print(min(odds))

if __name__ == "__main__":
    main()