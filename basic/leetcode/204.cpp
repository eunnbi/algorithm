int isPrime[5000001]; // 전역 변수로 선언
int countPrimes(int n){
	int cnt = 0;
	for (int i = 2; i < n; i++) isPrime[i] = 1;  // 모두 소수
	for (int i = 2; i < n; i++){
		if (!isPrime[i]) continue; // 소수가 아니면 건너뛰기
		for (int j = 2 * i; j < n; j += i) isPrime[j] = 0;
	}
	for (int i = 2; i < n; i++) cnt += isPrime[i];
	return cnt;
}

// 시간 초과 문제
// 에라토스테네스의 체 : 많은 수에 대해 소수를 판별할 때 사용됨
// https://leetcode.com/problems/count-primes/