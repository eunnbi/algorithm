def main():
    n = int(input())
    nums = [0] * 2000002
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