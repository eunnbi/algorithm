# Recursion

> **A function can call itself in its body**
>
> - We need to specify a stop condition
> - Each function call needs to do something useful.
> - The `return` keyword only terminates the function where it is called.
> - Variables in each function call are all different. They just have the same name.

<br/>

## When to Use Recursion? π€

1. Computing a sequence when a recursive definition is given.
   - Fibonacci sequence
   - Ultimately, you will do this using dynamic programming
2. **Exhaustive Search**: you need to generate and test all possibilities
   - generating all combinations or permutations
   - N-queen
   - Time complexity: `O(2^N)` or `O(N!)`
3. Traversing data structures
   - DFS, BFS (flood fill)
   - Time complexity: `O(number of nodes)`
4. The problem can be **divided into two smaller subproblems**
   - merge sort
   - divide and conquer
   - Time complexity : `O(NlogN)`

<br/>

## π Example

### The Tower of Hanoi Problem

```cpp
void hanoi(int n, char from, char via, char to){
	if (n == 1){
		printf("Move disk %d from rod %c to %c", n, from, to);
		return; // λ°λμ returnλ¬Έ μμ΄μΌ ν¨.
	}
	hanoi(n - 1, from, to, via);
	printf("Move disk %d from rod %c to %c", n, from, to);
	hanoi(n - 1, via, from, to);
}
```

### Generating Strings

- Given N, print out all strings of length N that only consist βaβ, βbβ, and βcβ.
- N = 4 : aaaa, aaab, aaac, aaba, aabb, ..., cccb, cccc

```cpp
int n = 4;
char res[10];
void f(int i){ // i : index of res
	if (i == n){  // condition of termination
		printf("%s\n", res);
		return; // return λ¬Έ λ°λμ μμ΄μΌ ν¨!!
	}
   // strings starting with 'a'
	res[i] = 'a';
	f(i + 1);

	// strings starting with 'b'
	res[i] = 'b';
	f(i + 1);

	// strings starting with 'c'
	res[i] = 'c';
	f(i + 1);
}
```

### β Generating Strings / Permutations / Combinations

1. Generating **strings** of length `n` using `k` numbers
   - `seq[i]` can be any of the k numbers
2. Generating **permutations** of length `n` using `n` numbers
   - `seq[i]` can be any or the n numbers that are not used in `seq[0:i-1]`
   - We maintained the _used_ array to check if each digit has been used or not
3. Generating **combinations** of length `k` using `n` numbers
   - `seq[i]` must be larger than `seq[i-l]` β increasing order
   - **We fill `seq[i]` using each digit in `[seq[i - 1] + 1, n]`**

<br/>

## π Limitations of Recursion

### 1. Repitition

the same problems are solved multiple times.

```c
int fibo(int n){
	if (n <= 1) return n;
	return fibo(n - 1) + fibo(n - 2);
}

int main(){
	printf("%d\n", fibo(10));
}

// Fibo(10) = Fibo(9) + Fibo(8) = (Fibo(8) + Fibo(7)) + Fibo(8)
// Fibo(8) is computed twice!
```

#### π Memoization

Remember the answer of a small problem by taking a memo to avoid the duplicate work caused by the branching

```c
int memo[100];

int fibo(int n){
	if (memo[n] >= 0) return memo[n];
	if (n <= 1) return n;
	return memo[n] = fibo(n - 1) + fibo(n - 2);
}

int main(){
	memset(memo, -1, sizeof(memo)); // νμ!!
	printf("%d\n", fibo(10));
	return 0;
}

// Fibo(10) = Fibo(9) + Fibo(8) = (Fibo(8) + Fibo(7)) + Fibo(8)
// Fibo(8) is computed twice!
```

Sometimes, it is needed to use more than one variable (other than N) to encode the state

- We use **multidimensional arrays** whose dimensions corresponds to the parameters of a recursive function
- reset all elements to -1 to indicate a memo is not taken

```c
// combination (n and k)

int memo[100][100] = { -1, };

int nck(int n, int k){
	if (k == 0 || n == k) return 1;
	if (memo[n][k] >= 0) return meno[n][k];
	return memo[n][k] = nck(n - 1, k - 1) + nck(n - 1, k);
}

int main(){
	memset(memo, -1, sizeof(memo)); // νμ!!
	printf("%d\n", nck(30, 10));
	return 0;
}
```

> Use memoization only when there are repetitive computations. It is not needed for the Tower of Hanoi problem or binary search

<br/>

### 2. Call Stack Overflow

- When a function is called, it creates a stack frame in a call stack, but the size of the call stack is limited
- If recursion goes too βdeepβ, we get a _stack overflow_ exception
  - You need to convert the algorithm non-recursive

<br/>

### 3. Excessive Search Space

- When you do exhaustive search (testing all possibilities), sometimes the search space is too big to be searched in time.

#### π Pruning

- You need to **prune** the search tree by rejecting unpromising solutions ASAP.
- narrow down search space

<br/>

## Common mistakes π€¦ββοΈ

1. Initialize the memo array to a value that can be an answer ex) `0`

   - Initialize the memo array to a blue that cannot be an answer ex) `-1`

2. The problem size does not decrease
   - Make sure that the problem size always decreases to reach the stop condition
3. Skipping the stop condition

   ```c
   int fibo(int n){
   	if (n == 1) return 1;
   	return fibo(n - 1) + fibo(n - 2);
   }

   //  if n == 2, fibo(0) is called, with skips the stop condition
   ```

4. Recursion first
   - Always check the stop condition first, and then do recursion
5. Memo taken but not used

<br/>

## π‘ Tip

1. **κ·λ©μ  μ¬κ³  λ°©μ**
   - ex) 1λ² λλ―ΈλΈκ° μ°λ¬μ§λ€. kλ² λλ―ΈλΈκ° μ°λ¬μ§λ€. k+1λ² λλ―ΈλΈλ μ°λ¬μ§λ€.
2. **ν¨μμ νν μ μνκΈ°**: μΈμ, λ°νκ°
3. **base condition μ μνκΈ°**
4. **μ¬κ·μ μ μνκΈ°**
   - `base condition`μ λλ¬νλλ‘ `problem` μ¬μ΄μ¦λ μμμ ΈμΌ νλ€.

<br/>

## β Problems

| Leetcode                                                                                                         | BOJ                                                                                         |
| :--------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------- |
| [Find K-th Bit in N-th Binary String](https://github.com/eunnbi/algorithm/blob/main/recursion/leetcode/1545.cpp) | [κ³±μ](https://github.com/eunnbi/algorithm/blob/main/recursion/BOJ/1629.cpp)                |
| [Predict the Winner](https://github.com/eunnbi/algorithm/blob/main/recursion/leetcode/486.cpp)                   | [νλΈμ΄ ν](https://github.com/eunnbi/algorithm/blob/main/recursion/BOJ/11729.cpp)          |
| [Sum of All Subset XOR Totals](https://github.com/eunnbi/algorithm/blob/main/recursion/leetcode/1863.cpp)        | [Z](https://github.com/eunnbi/algorithm/blob/main/recursion/BOJ/1074.cpp)                   |
| [Permutation Sequence](https://github.com/eunnbi/algorithm/blob/main/recursion/leetcode/60.cpp)                  | [μ¬κ·ν¨μκ° λ­κ°μ?](https://github.com/eunnbi/algorithm/blob/main/recursion/BOJ/17478.cpp) |
| [Combinations](https://github.com/eunnbi/algorithm/blob/main/recursion/leetcode/77.cpp)                          | [μ’μ΄μ κ°μ](https://github.com/eunnbi/algorithm/blob/main/recursion/BOJ/1780.cpp)         |
| [Target Sum](https://github.com/eunnbi/algorithm/blob/main/recursion/leetcode/494.cpp)                           | [μμ’μ΄ λ§λ€κΈ°](https://github.com/eunnbi/algorithm/blob/main/recursion/BOJ/2630.cpp)       |
| [Letter Tile Possibilities](https://github.com/eunnbi/algorithm/blob/main/recursion/leetcode/1079.cpp)           | [μΏΌλνΈλ¦¬](https://github.com/eunnbi/algorithm/blob/main/recursion/BOJ/1992.cpp)            |
| [N-Queens 2](https://github.com/eunnbi/algorithm/blob/main/recursion/leetcode/52.cpp)                            | [λ³μ°κΈ° 10](https://github.com/eunnbi/algorithm/blob/main/recursion/BOJ/2447.cpp)           |
| [Number of Ways of Cutting Pizza](https://github.com/eunnbi/algorithm/blob/main/recursion/leetcode/1444.cpp)     | [λ³μ°κΈ° 11](https://github.com/eunnbi/algorithm/blob/main/recursion/BOJ/2448.cpp)           |
