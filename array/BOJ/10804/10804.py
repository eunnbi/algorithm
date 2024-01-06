def main():
    list = [i for i in range(21)]
    for i in range(10):
        str = input()
        nums = [int(i) for i in str.split(' ')]
        start = nums[0]
        end = nums[0] + int(((nums[1] - nums[0] + 1) / 2))
        for j in range(start, end):
            temp = list[j]
            list[j] = list[nums[1] + nums[0] - j]
            list[nums[1] + nums[0] - j] = temp
    for i in range(1, len(list)):
        print(list[i], end=' ')

if __name__ == "__main__":
    main()