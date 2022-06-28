int trailingZeroes(int n){
	int cnt = 0;
	for (int i = 5; i <= n; i *= 5) cnt += n / i;
	return cnt;
}

// factorial를 직접 구하면 Integer Overflow 발생
// 대신 factorial에서 10이 몇 번 곱해졌는지 구하면 된다.
// https://leetcode.com/problems/factorial-trailing-zeroes/