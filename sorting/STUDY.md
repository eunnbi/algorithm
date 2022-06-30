# Sorting

## 📝 Sorting Algorithms

|   Algorithm    | Best Time Complexity | Average Time Complexity | Worst Time Complexity |
| :------------: | :------------------: | :---------------------: | :-------------------: |
|   Quick Sort   |       O(NlogN)       |        O(NlogN)         |        O(N^2)         |
|   Merge Sort   |       O(NlogN)       |        O(NlogN)         |       O(NlogN)        |
|   Heap Sort    |       O(NlogN)       |        O(NlogN)         |       O(NlogN)        |
|  Bubble Sort   |         O(N)         |         O(N^2)          |        O(N^2)         |
| Insertion Sort |         O(N)         |         O(N^2)          |        O(N^2)         |
| Selection Sort |        O(N^2)        |         O(N^2)          |        O(N^2)         |
|   Radix Sort   |        O(NK)         |          O(NK)          |         O(NK)         |
| Counting Sort  |        O(N+K)        |         O(N+K)          |        O(N+K)         |

<br/>

## Comparison 🆚 Non-comparison

1. Comparison sorting algorithms : algorithms that **compare two numbers to sort them**
   - Minimum time complexity : O(NlogN)
   - O(logN!) = O(NlogN)
2. Non-comparison sorting algorithms : **do not use comparison**
   - 🚧 **Constraints**: we need to know the distribution of input number
   - ex) natural numbers less than 1000
   - radix sort, counting sort

<br/>

## Selection Sort

- Easy to implement
- Useful if input is small
- Slow

```cpp
void selectionSort(int arr[], int n){
	int min, temp;
	for (int i = 0; i < n - 1; i++){
		min = i;
		for (int j = i + 1; j < n; j++){
			if (arr[j] < arr[min]){
				min = j;
			}
		}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}
```

<br/>

## Merge Sort vs Quick Sort vs Heap Sort

Time complexity : `O(NlogN)`

Merge Sort

- Stable
- Requires additional memory (temporary array)

Quick Sort

- Practically, fastest (cache friendly), No additional memory
- not stable, bad worst time complexity (`O(N^2)`)

Heap Sort

- Not stable

```cpp
int sorted[MAX_SIZE];
void merge(int arr[], int left, int mid, int right){
	int first = left, second = mid + 1, i = left;
	while (first <= mid && second <= right){
		if (arr[first] < arr[second]){
			sorted[i++] = arr[first++];
		}
		else {
			sorted[i++] = arr[second++];
		}
	}
	while (first <= mid){
		sorted[i++] = arr[first++];
	}
	while (second <= right){
		sorted[i++] = arr[second++];
	}
	for (int j = left; j <= right; j++){
		arr[j] = sorted[j];
	}
}

void mergeSort(int arr[], int left, int right){
	if (left < right){
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

// Time complexity : O(NlogN)
// Space complexity : O(N)
```

<br/>

## Counting Sort

- Efficient when the distribution of numbers is **dense**

```cpp
int arr[] = {0, 5, 4, 2, 12, 8, 7, 25, 13, 17, 18};
int count[26];

void countingSort(int arr[], int n){
	for (int i = 0; i < n; i++) count[arr[i]]++;
	int index = 0;
	for (int i = 0; i < 26; j++){
		while (count[i]){
			arr[index++] = i;
			count[i]--;
		}
	}
}

// Time complexity: O(N+K)
// Space complexity: O(N)
```

<br/>

## ❓ Problems

| Leetcode                                                                                                          |
| :---------------------------------------------------------------------------------------------------------------- |
| [Minimum Moves to Equal Array Elements 2](https://github.com/eunnbi/algorithm/blob/main/sorting/leetcode/462.cpp) |
