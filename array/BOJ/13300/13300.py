import math

def main():
    room = [[0 for col in range(2)] for row in range(6)] # 이차원 배열 선언
    n, k = input().split(' ')
    n = int(n)
    k = int(k)
    for i in range(n):
        s, y = input().split(' ')
        s = int(s)
        y = int(y)
        room[y - 1][s] += 1 # 이차원 배열 인덱싱: arr[row][col]
    res = 0
    for i in range(6):
        for j in range(2):
            res += math.ceil(room[i][j] / k)
    print(res)

if __name__ == "__main__":
    main()