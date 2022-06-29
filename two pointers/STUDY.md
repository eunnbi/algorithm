# Two Pointers

> maintain two pointers that determine the range of search and move one pointer to narrow down the search space

<br/>

### Example

- Given a sorted array, find two elements whose sum is M.
- If `a[i] + a[j] > M`, you don’t have to check `a[i] + a[k]` where `k > j` because the array is sorted.

<br/>

### 🎯 Target Problems

1. The problem requires search on the array.
2. The array is sorted, or you can sort it by yourself without violating the constraints
3. The search process can be stated by two variables.
4. The search is performed in a contiguous range.
5. Naive search takes `O(N^2)` or `O(N^3)` which exceeds the time limit.
6. Evaluating a point in the search space tells a lot about the remaining space.
   - rejecting many cases base on the result

<br/>

### Type

- `Increasing` two pointers: start from (0, 0), i++ or j++ until i < j < N
- `Narrowing` two pointers: start from (0, N), i++ or j-- until i < j
- Consider Both Directions!!
