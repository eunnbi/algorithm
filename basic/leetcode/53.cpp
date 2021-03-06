#include <limits.h>
int maxSubArray(int* nums, int numsSize){
	int max_sum = INT_MIN, sum = 0;
	for (int i = 0; i < numsSize; i++){
		if (sum >= 0) sum += nums[i];
		else sum = nums[i];

		if (sum > max_sum) max_sum = sum;
	}
	return max_sum;
}

// Naive Approach: ìê°ì´ê³¼
/*
ð¤ sumì ì´ë»ê² ìë°ì´í¸í´ì¼ í ê¹??
"Greedy Approach"
- sum >= 0 : íì¬ ììë¥¼ ëí´ ìë°ì´í¸
- sum < 0 : sumì íì¬ ììê°ì¼ë¡ ì´ê¸°ííì¬ ë¤ì ìì
*/

/*
Advanced : í©ì´ ìëë¼ ê³±ì´ ìµëì¸ ë¶ë¶ ë°°ì´ êµ¬íê¸°
=> ê° ë°°ì´ì ììì logë¥¼ ì·¨í ë¤ì ìì ìê³ ë¦¬ì¦ì¼ë¡ êµ¬íë©´ ëë¤.
*/

// https://leetcode.com/problems/maximum-subarray/