def main():
    sum = 0
    nums = []
    for i in range(5):
        num = int(input())
        sum += num
        nums.append(num)
    nums.sort()
    print(int(sum / len(nums)))
    print(nums[2])
        

if __name__ == "__main__":
    main()
    