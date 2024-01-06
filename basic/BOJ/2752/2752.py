def main():
    str = input()
    list = str.split(' ')
    nums = [int(i) for i in list]
    nums.sort()
    print(f"{nums[0]} {nums[1]} {nums[2]}")

if __name__ == "__main__":
    main()
