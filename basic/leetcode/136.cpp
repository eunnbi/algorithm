// 1. 공간복잡도가 크다
int number[60001]; // 전역 변수로 선언
int singleNumber(int* nums, int numsSize){
    int res;
    for (int i = 0; i < numsSize; i++){
        number[nums[i] + 30000]++; // nums 배열에 음수도 포함됨
    }
    for (int i = 0; i <= 60000; i++){
        if (number[i] == 1) {
            res = i - 30000;
            break;
        }
    }
    return res;
}


// 2. XOR 연산 이용
// single number가 아닌 나머지 원소들은 2번씩 나오기 때문에 가능
// - a ^ a == 0
// - 0 ^ a == a
int singleNumber(int* nums, int numsSize){
	int res = nums[0];
	for (int i = 1; i < numsSize; i++){
		res ^= nums[i];
	}
	return res;
}


// https://leetcode.com/problems/single-number/