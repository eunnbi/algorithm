int trailingZeroes(int n){
	int cnt = 0;
	for (int i = 5; i <= n; i *= 5) cnt += n / i;
	return cnt;
}

// factorial를 직접 구하면 Integer Overflow 발생
// 대신 factorial에서 10이 몇 번 곱해졌는지 구하면 된다.
// factorial에서 항상 2의 개수가 5의 개수보다 많으므로 5가 몇 번 곱해지는지를 구하면 된다.
// 최종!! 5의 배수, 25의 배수, 5^3의 배수를 차례대로 구하면 된다.
// https://leetcode.com/problems/factorial-trailing-zeroes/