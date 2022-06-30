# Linked List

## Floyd's Tortoise 🐢 and Hare 🐇 Algorithm

**Detecting the First Element in the Loop**

- Two Pointers
  - Slow Pointer (tortoise): moves by 1 node at a time
  - Fast Pointer (hare): moves by 2 node at a time
- S and F point to the same node. A loop is detected.
- If a loop is found, we want to find the first element of the loop.
- Move S to the beginning and move forward both points by 1 node at a time.
- S and F met. This is the first element in the loop.

<br/>

## ❓ Problems

| Leetcode                                                                                                        |
| :-------------------------------------------------------------------------------------------------------------- |
| [Add Two Numbers](https://github.com/eunnbi/algorithm/blob/main/linked%20list/leetcode/2.cpp)                   |
| [Remove nth Node from End of List](https://github.com/eunnbi/algorithm/blob/main/linked%20list/leetcode/19.cpp) |
| [Merge k Sorted Lists](https://github.com/eunnbi/algorithm/blob/main/linked%20list/leetcode/23.cpp)             |
