import math

def main():
    str = input()
    list = [0] * 10
    for char in str:
        list[int(char)] += 1
    list[6] = math.ceil((list[6] + list[9]) / 2)
    list[9] = 0
    print(max(list))

if __name__ == "__main__":
    main()