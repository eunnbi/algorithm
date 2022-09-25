# Dynamic Programming

> The method for solving complex problems by **breaking them down into simpler subproblems**

<br/>

## Top-down 🆚 Bottom-up

1. Solutions using recursive function calls → **Top-down**
   - Start from original “big” problem and split it into smaller problems until you meet base cases
   - Computation can be repeated → Memoization
2. Without recursive function calls → **Bottom-up**
   - Start from the base cases (the smallest problem), and solve the next big problem until we reach the original big problem
   - Constructive

<br/>

## 👟 Step for Solving DP problems

1. Check if the problem is a DP problem
2. **Define a subproblem** (테이블 정의하기)
3. **Define base cases** (초기값 정하기)
4. **Define the answer case**
5. Identify the **recurrence** that relates subproblems (점화식 찾기)

### Smells of DP

- There are some `strings`, `arrays`, `sequences`, `sets` in the problem
- The problem asks for a `minimum`, `maximum`, `optimum` value. ⇒ optimization problem

<br/>

## Example

### 1. Ways of Expressing a Number

- Problem: count the number of different ways of expressing a number as the sum of 1, 3, and 5.

1. Define a subproblem: Let `A[i]` be the number of ways of expressing `i`.
2. Define base cases: `A[0] = 1`
3. Define the answer case: `A[n]`
4. Identify the recurrence

   - Suppose we want to compute `A[i]`
   - We know `A[1] ~ A[i-1]`
   - Then, `A[i] = A[i-1] + A[i-3] + A[i-5]`

```cpp
int dp[100], n = 10;
int main(){
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + (i >= 3 ? dp[i - 3]: 0) + (i >= 5 ? dp[i - 5] : 0);
    }
}

```

   <br/>

#### 🚀 Advanced

- What if we can use more numbers, like [1, 3, 5, 9]?

  ```cpp
  int dp[100], n = 10;
  int main(){
      dp[0] = 1;
      for (int i = 1; i <= n; i++){
          dp[i] = dp[i - 1] + ((i >= 3) ? dp[i - 3] : 0) + ((i >= 5) ? dp[i - 5] : 0) + ((i >= 9) ? dp[i - 9] : 0);
      }
  }
  ```

- What if the numbers in an expression should appear in non-decreasing order

  ```cpp
  #include <stdio.h>
  int dp[100][4] = { 0, }; // 2차원 배열로 변경
  int n = 9;
  int nums[4] = { 1, 3, 5, 9 };
  int main(){
      for (int i = 0; i < 4; i++){
          dp[0][i] = 0;
      }

      for (int i = 1; i <= n; i++){
          for (int j = 0; j < 4; j++){
              if (i < nums[j]) dp[i][j] = 0;
              else if (i == nums[j]) dp[i][j] = 1;
              else {
                  for (int k = 0; k <= j; k++) dp[i][j] += dp[i - nums[j]][k];
              }
          }
      }
      return 0;
  }
  ```

<br/>

### 2. Collecting numbers

- Problem : find the path that maximizes the sum. (Move only right or bottom)
- Focus only the present and the past
  - Suppose the cat is at (3,3)
  - The cat is from (2,3) or (3,2)
- `nums[i][j]` = the number at (i, j)
- `a[i][j]` = the maximum sum that the cat can collect when it moves from (1, 1) to (i, j)
- Base case
  - a[1][1] = nums[1][1]
  - a[1][i] = a[1][i - 1] + nums[1][i]
  - a[i][1] = a[i - 1][1] + nums[i][1]
- Answer : a[n][n]

```c
int n = 5;
int a[6][6];
int nums[6][6] = {
	{0, 0, 0, 0, 0},
	{0, 2, 5, -3, -4, 3},
    {0, 20, -100, 3, 10, 7},
    {0, -100, 7, 8, 6, 4},
    {0, 4, 6, 6, 6, 5},
    {0, 5, 2, 1, 3, 2},
};

void backtrack(int i, int j){
	if (i == 1 && j == 1){
		printf("(1, 1) ");
		return;
	}
	if (a[i - 1][j] > a[i][j - 1]) backtrack(i - 1, j);
	else backtrack(i, j - 1);
	printf("> (%d, %d)", i, j);
}

int main(){
	a[1][1] = 1;
	for (int i = 2; i <= n; i++) a[1][i] = arr[1][i - 1] + nums[1][i];
	for (int i = 2; i <= n; i++) a[i][1] = arr[i - 1][1] + nums[i][1];

	for (int i = 2; i <= n; i++){
		for (int j = 2; j <= n; j++){
			if (a[i - 1][j] > a[i][j - 1]) a[i][j] = a[i - 1][j] + nums[i][j];
			else a[i][j] = a[i][j - 1] + nums[i][j];
		}
	}
	backtrack(n, n);
	return 0;
}
```

<br/>

### 3. Building 27

- Problem: There are `N` stairs. You can climb up to `M` but not `K` stairs at a time.
- Base Case: `T[0] = 1`
- `sum = sum + T[i - 1] - T[i - M - 1]`
- `T[i] = sum - T[i - K]`

```c
int dp[1000000];
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	dp[0] = 1;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += dp[i - 1];
		if (i - m - 1 >= 0) sum -= dp[i - 1 - m]; // index 주의!!
 		int last_k = 0; // 0으로 초기화
		if (i - k >= 0) last_k = dp[i - k]; // index 주의!!
		dp[i] = sum - last_k;
	}
}
```

<br/>

### 4. Knapsack Problem

<br/>

## ❓ Problems

| Leetcode                                                                                                                |
| :---------------------------------------------------------------------------------------------------------------------- |
| [Longest Increasing Subsequence](https://github.com/eunnbi/algorithm/blob/main/dynamic%20programming/leetcode/300.cpp)  |
| [Longest Common Subsequence](https://github.com/eunnbi/algorithm/blob/main/dynamic%20programming/leetcode/1143.cpp)     |
| [Longest Palindromic Subsequence](https://github.com/eunnbi/algorithm/blob/main/dynamic%20programming/leetcode/516.cpp) |
| [Partition Equal Subset Sum](https://github.com/eunnbi/algorithm/blob/main/dynamic%20programming/leetcode/416.cpp)      |
| [Wildcard Matching](https://github.com/eunnbi/algorithm/blob/main/dynamic%20programming/leetcode/44.cpp)                |
| [Edit Distance](https://github.com/eunnbi/algorithm/blob/main/dynamic%20programming/leetcode/72.cpp)                    |
| [Perfect Squares](https://github.com/eunnbi/algorithm/blob/main/dynamic%20programming/leetcode/279.cpp)                 |
| [Burst Balloons](https://github.com/eunnbi/algorithm/blob/main/dynamic%20programming/leetcode/312.cpp)                  |
