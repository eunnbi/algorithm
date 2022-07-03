#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
    int n; // 배열 가로세로 크기 (1 <= n <= 10)
	int arr[10][10] = { 0, }; // 0으로 초기화
	
	int number = 1; // 원소값
	int row = 0, col = 0; // 가로 세로 인덱스
    char direction[4] = { 'E', 'S', 'W', 'N' };
	int currentDirectionIndex = 0;


	printf("# 행/열의 수 입력 : ");
	scanf("%d", &n);

	
	while (number <= n * n) {
		arr[row][col] = number;
		if (direction[currentDirectionIndex] == direction[0]) {
			col++;
			if (col >= n || arr[row][col]) {
				col--;
				row++;
				currentDirectionIndex = (currentDirectionIndex + 1) % 4;
			}
		}
		else if (direction[currentDirectionIndex] == direction[1]) {
			row++;
			if (row >= n || arr[row][col]) {
				row--;
				col--;
				currentDirectionIndex = (currentDirectionIndex + 1) % 4;
			}
		}
		else if (direction[currentDirectionIndex] == direction[2]) {
			col--;
			if (col < 0 || arr[row][col]) {
				col++;
				row--;
				currentDirectionIndex = (currentDirectionIndex + 1) % 4;
			}
		}
		else {
			row--;
			if (row < 0 || arr[row][col]) {
				row++;
				col++;
				currentDirectionIndex = (currentDirectionIndex + 1) % 4;
			}
		}
		
		number++;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%*d ", (n == 10) ? 3 : ((n == 3) ? 1 : 2), arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
💡 똬리 배열의 핵심은 "배열을 채우는 순서와 방향"이다. 즉, row, col 인덱스의 규칙을 찾아야 한다. 
💡 인덱스가 배열의 범위를 벗어나지 않게 체크해야 하고, 이미 채워진 자리에 다시 원소를 채우지 않도록 체크해야 한다.
*/