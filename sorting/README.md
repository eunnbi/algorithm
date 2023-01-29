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
// Merge Sort
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

## Radix Sort

```cpp
int n = 15;
int arr[1000001] = {12, 421, 46, 674, 103, 502, 7, 100, 21, 545, 722, 227, 62, 91, 240};

// 1, 10, 100의 자리에 대해서 진행, 수가 최대 3자리수가 아닐 경우 d를 조절해야 함
int d = 3;
int p10[3]; // p10[i] = 10의 i승
vector<int> l[10]; // 0 ~ 9

// x의 10^a 자리의 값을 반환하는 함수
int digitNum(int x, int a){
  return (x / p10[a]) % 10;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  p10[0] = 1;
  for(int i = 1; i < d; i++) p10[i] = p10[i-1] * 10;

  for(int i = 0; i < d; i++){
    for(int j = 0; j < 10; j++) l[j].clear();

    // 각 수를 list에 대입
    for(int j = 0; j < n; j++)
      l[digitNum(arr[j], i)].push_back(arr[j]);

    // 0번 리스트부터 차례로 다시 arr에 넣어 재배열
    int aidx = 0;
    for(int j = 0; j < 10; j++){
      for(auto x : l[j]) arr[aidx++] = x;
    }
  }
  for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}
```

<br/>

## STL sort

```cpp
// 기본 : 오름차순 정렬
int a[5] = { 1, 4, 5, 2, 7 };
sort(a, a + 5);

vector<int> b = { 1, 4, 5, 2, 7 };
sort(b.begin(), b.end()); // or sort(b.begin(), b.begin() + 5);
```

```cpp
// 내림차순 정렬
bool cmp(int a, int b){
	return a > b;
}
int a[5] = { 1, 4, 5, 2, 7 };
sort(a, a + 5, cmp);
```

- 비교 함수에서 `a`가 `b`의 앞에 와야할 때 `true`, 그렇지 않을 때 `false`를 반환해야 함.

```cpp
bool cmp(int a, int b){
	if (a % 5 != b % 5) return a % 5 < b % 5;
	return a < b;
}
int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
sort(a, a + 7, cmp); // 5, 1, 6, 2, 7, 3, 4
```

- 비교 함수는 두 값이 같을 때 (혹은 우선순위가 같을 때) `false`를 반환하도록 해야 함.

```cpp
// **WRONG**
bool cmp(int a, int b) {
	if (a >= b) return true;
	return false;
}

// RIGHT
bool cmp(int a, int b) {
	return a > b;
}
```

- 비교 함수의 인자로 STL 혹은 클래스 객체를 전달 시 `reference`를 사용해야 함.

```cpp
// 바람직하지 않음. 값의 복사로 인자가 전달되어 비용 발생
bool cmp(string a, string b) {
	return a.back() < b.back();
}

// GOOD
bool cmp(const string& a, const string& b){
	return a.back() < b.back();
}

```

<br/>

## ❓ Problems

| Leetcode                                                                                                          |
| :---------------------------------------------------------------------------------------------------------------- |
| [Minimum Moves to Equal Array Elements 2](https://github.com/eunnbi/algorithm/blob/main/sorting/leetcode/462.cpp) |
