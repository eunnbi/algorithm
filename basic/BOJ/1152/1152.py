def main():
    str = input()
    list = str.split(' ')
    res = 0
    for char in list:
        if (char != ''):
            res += 1
    print(res)


if __name__ == "__main__":
    main()