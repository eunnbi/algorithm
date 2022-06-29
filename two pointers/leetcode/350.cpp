#include <stdlib.h>

int count[1001] = { 0, }; // freq array!!

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int size = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int * res = (int *)malloc(sizeof(int) * size);
    
    for (int i = 0; i < nums1Size; i++) count[nums1[i]]++;
    
    int index = 0;
    for (int i = 0; i < nums2Size; i++){
        if (count[nums2[i]]) {
            count[nums2[i]]--;
            res[index++] = nums2[i];
        }
    }
    *returnSize = index;
    return res;
}

// O(N + M)
// https://leetcode.com/problems/intersection-of-two-arrays-ii/


// 🚀 Advanced
/*
1) 만약 배열의 길이가 크지 않다면, 최적화 안해도 상관없음. => O(N + M)
2) 배열의 길이가 매우 크다면, "sorting" 과 "two pointer" 를 이용해야 한다.
3) 배열의 길이가 매우 크지만 정렬이 되어 있는 경우 "two pointer" 이용하면 된다.
*/

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    // sorted array, nums1 and nums2
    int size = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int * res = (int *)malloc(sizeof(int) * size);

    int i = 0, j = 0; // two pointers
    int index = 0;
    while (i < nums1Size && j < nums2Size){
        if (nums1[i] == nums2[j]) {
            res[index++] = nums1[i];
            i++; j++;
        }
        else if (nums1[i] < nums2[j]) i++;
        else j++;
    }
    
    *returnSize = index;
    return res;
}


// 중복 없는 교차 배열을 구하기
// https://leetcode.com/problems/intersection-of-two-arrays/
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int size = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int * res = (int *)malloc(sizeof(int) * size);
    int count[1001] = { 0, };
    
    for (int i = 0; i < nums1Size; i++) count[nums1[i]]++;
    
    int index = 0;
    for (int i = 0; i < nums2Size; i++){
        if (count[nums2[i]]) {
            count[nums2[i]] = 0; // 변경된 부분
            res[index++] = nums2[i];
        }
    }
    *returnSize = index;
    return res;
}