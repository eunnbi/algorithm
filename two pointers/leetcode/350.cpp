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


// ๐ Advanced
/*
1) ๋ง์ฝ ๋ฐฐ์ด์ ๊ธธ์ด๊ฐ ํฌ์ง ์๋ค๋ฉด, ์ต์ ํ ์ํด๋ ์๊ด์์. => O(N + M)
2) ๋ฐฐ์ด์ ๊ธธ์ด๊ฐ ๋งค์ฐ ํฌ๋ค๋ฉด, "sorting" ๊ณผ "two pointer" ๋ฅผ ์ด์ฉํด์ผ ํ๋ค.
3) ๋ฐฐ์ด์ ๊ธธ์ด๊ฐ ๋งค์ฐ ํฌ์ง๋ง ์ ๋ ฌ์ด ๋์ด ์๋ ๊ฒฝ์ฐ "two pointer" ์ด์ฉํ๋ฉด ๋๋ค.
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


// ์ค๋ณต ์๋ ๊ต์ฐจ ๋ฐฐ์ด์ ๊ตฌํ๊ธฐ
// https://leetcode.com/problems/intersection-of-two-arrays/
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int size = (nums1Size < nums2Size) ? nums1Size : nums2Size;
    int * res = (int *)malloc(sizeof(int) * size);
    int count[1001] = { 0, };
    
    for (int i = 0; i < nums1Size; i++) count[nums1[i]]++;
    
    int index = 0;
    for (int i = 0; i < nums2Size; i++){
        if (count[nums2[i]]) {
            count[nums2[i]] = 0; // ๋ณ๊ฒฝ๋ ๋ถ๋ถ
            res[index++] = nums2[i];
        }
    }
    *returnSize = index;
    return res;
}