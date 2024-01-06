def main():
    str = input()
    temp = str.split(' ')
    nums = [int(i) for i in temp]
    nums.sort()
    a = int(nums[0])
    b = int(nums[1])
    if (a == b):
        print(0)
    else:
        print(b - a - 1)
        for i in range(a + 1, b):
            print(i, end=' ')


if __name__ == "__main__":
    main()