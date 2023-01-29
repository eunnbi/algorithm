# Two Pointers

> maintain two pointers that determine the range of search and move one pointer to narrow down the search space

<br/>

## 🎯 Target Problems

1. The problem requires search on the array.
2. The array is sorted, or you can sort it by yourself without violating the constraints
3. The search process can be stated by two variables.
4. The search is performed in a contiguous range.
5. Naive search takes `O(N^2)` or `O(N^3)` which exceeds the time limit.
6. Evaluating a point in the search space tells a lot about the remaining space.
   - rejecting many cases base on the result

### Example

- Given a sorted array, find two elements whose sum is M.
- If `a[i] + a[j] > M`, you don’t have to check `a[i] + a[k]` where `k > j` because the array is sorted.

<br/>

## Type

- `Increasing` two pointers: start from (0, 0), i++ or j++ until i < j < N
- `Narrowing` two pointers: start from (0, N), i++ or j-- until i < j
- Consider Both Directions!!

<br/>

> 👉 Reference: [Two Pointers Algorithm](https://blog.naver.com/kks227/220795165570)

<br/>

## ❓ Problems

| Leetcode                                                                                                                      |
| :---------------------------------------------------------------------------------------------------------------------------- |
| [Container With Most Water](https://github.com/eunnbi/algorithm/blob/main/two%20pointers/leetcode/11.cpp)                     |
| [Maximum Score of a Good Subarray](https://github.com/eunnbi/algorithm/blob/main/two%20pointers/leetcode/1793.cpp)            |
| [Sliding Window Max](https://github.com/eunnbi/algorithm/blob/main/two%20pointers/leetcode/239.cpp)                           |
| [Longest Substring Without Repeating Characters](https://github.com/eunnbi/algorithm/blob/main/two%20pointers/leetcode/3.cpp) |
| [Intersection of Two Arrays II](https://github.com/eunnbi/algorithm/blob/main/two%20pointers/leetcode/350.cpp)                |
| [Subarray Product Less Than K](https://github.com/eunnbi/algorithm/blob/main/two%20pointers/leetcode/713.cpp)                 |
| [Longest Mountain in Array](https://github.com/eunnbi/algorithm/blob/main/two%20pointers/leetcode/845.cpp)                    |
