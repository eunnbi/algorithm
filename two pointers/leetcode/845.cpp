int longestMountain(int* arr, int arrSize){
    if (arrSize < 3) return 0;
    int max = 0; // the length of the longest subarray

    for (int right = 1; right < arrSize - 1; right++){ // 봉우리는 양쪽 끝 X
	if (arr[right - 1] > arr[right] || arr[right] <= arr[right + 1]) continue; // 봉우리 찾기

        // two pointers를 이용하여 봉우리를 기준으로 왼쪽 오른쪽 구간 찾기
	int left = right - 1;
	right++;
	while (left > 0 && arr[left - 1] < arr[left]) left--;
	while (right < arrSize - 1 && arr[right] > arr[right + 1]) right++;
	if (right - left + 1 > max) max = right - left + 1;
    }
    return max;
}

// https://leetcode.com/problems/longest-mountain-in-array/
