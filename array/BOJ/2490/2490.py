def main():
    for i in range(3):
        zero = 0
        str = input()
        list = str.split(' ')
        nums = [int(i) for i in list]
        for num in nums:
            if (num == 0):
                zero += 1
        if (zero == 1):
            print('A')
        elif (zero == 2):
            print('B')
        elif (zero == 3):
            print('C')
        elif (zero == 4):
            print('D')
        else:
            print('E')


if __name__ == "__main__":
    main()