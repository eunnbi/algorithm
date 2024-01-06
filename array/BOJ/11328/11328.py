def main():
    n = int(input())
    for _ in range(n):
        a, b = input().split(' ')
        eng = [0] * 26
        for char in a:
            eng[ord(char) - ord("a")] += 1
        for char in b:
            eng[ord(char) - ord("a")] -= 1
        if (min(eng) == 0) and (max(eng) == 0):
            print("Possible")
        else:
            print("Impossible")


if __name__ == "__main__":
    main()