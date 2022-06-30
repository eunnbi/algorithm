# Binary Search

> **Time Complexity**
>
> - `logN` terms usually appear when you **divide the problem (or data) into two (or k) pieces.** ✌️
> - Data structures / algorithms that introduce `logN` terms
>   - **Binary Search**
>   - **Sort algorithms (quick sort, merge sort, ...)**
>   - **Partition (recursion)**
>   - Tree data structues (red-black tree, interval tree, ...)
>   - Priority queue (Binary heap, Fibonacci heap, ...)

<br/>

## What is Binary Search??

You want to find the index of a target in a **sorted array**.

💡 Idea: Compare the target with the middle element.

- if target == arr[mid]: return mid
- if target < arr[mid]: continue searching on the left subarray
- if target > arr[mid]: continue searching on the right subarray

Time complexity: `O(logN)`

```cpp
// Recursion
int binary_search(int arr[], int l, int r, int target){
	if (l > r) return -1;
	int mid = l + (r - l) / 2;
	if (arr[mid] == target) return mid;
	else if (arr[mid] < target) return binary_search(arr, mid + 1, r, target);
	else return binary_search(arr, l, mid - 1, target);
}
```

```cpp
// loop
int binary_search(int arr[], int l, int r, int target){
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (arr[mid] == target) return mid;
		else if (arr[mid] < target) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}
```

<br/>

## What happens if the target occurs multiple times in the array? 🤔

ex) {1, 3, 4, 5, 5, 5, 5, 7, 9}, target = 5

- index of first occurrence
- index of last occurrence
- index of least element greater than target
- index of greatest element less than target

```cpp
// index of first occurence

int search(int arr[], int l, int r, int target){
	int ans = -1; // -1로 초기화
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (arr[mid] == target) {
			ans = mid;
			r = mid - 1;
		}
		else if (arr[mid] < target) l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
```

```cpp
// index of last occurence

int search(int arr[], int l, int r, int target){
	int ans = -1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (arr[mid] == target) {
			ans = mid;
			l = mid + 1;
		}
		else if (arr[mid] < target) l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
```

```cpp
// index of least element greater than target

int search(int arr[], int l, int r, int target){
	int ans = -1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (arr[mid] == target) l = mid + 1;
		else if (arr[mid] < target) l = mid + 1;
		else {
			ans = mid;
			r = mid - 1;
		}
	}
	return ans;
}
```

```cpp
// index of greater element less than target

int search(int arr[], int l, int r, int target){
	int ans = -1;
	while (l <= r){
		int mid = l + (r - l) / 2;
		if (arr[mid] == target) r = mid - 1;
		else if (arr[mid] < target) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}
```

<br/>

## Common Mistakes 🤦‍♀️

1. `while (l < r)`
   - You need to compare even when `l == r`
   - Change it to `while (l <= r)`
2. `binary_search(arr, 0, n, target)`
   - `r` should point to the last element in the array
   - Change it to `binary_search(arr, 0, n - 1, target)`
3. least(target) is not last(target) + 1
   - Target can be the last element
   - Target can be missing
   - **Always mind cases where targets do not exist in the array → return 값을 -1로 초기화**
4. Applies binary search to _unsorted_ arrays → sorting 후 binary search 진행

<br/>

## Binary Search on Solution Space

- Usually we perform binary search on the given input.
- But, “Tricky” BS problems require BS on the solution space.

<br/>

## ❓ Problems

| Leetcode                                                                                                                   |
| :------------------------------------------------------------------------------------------------------------------------- |
| [Search in Rotated Sorted Array](https://github.com/eunnbi/algorithm/blob/main/binary%20search/leetcode/33.cpp)            |
| [Capacity To Ship Packages Within D Days](https://github.com/eunnbi/algorithm/blob/main/binary%20search/leetcode/1011.cpp) |
| [Nth Digit](https://github.com/eunnbi/algorithm/blob/main/binary%20search/leetcode/400.cpp)                                |
| [H-Index 2](https://github.com/eunnbi/algorithm/blob/main/binary%20search/leetcode/275.cpp)                                |
