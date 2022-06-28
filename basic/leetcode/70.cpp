int climbStairs(int n){
	int a = 0, b = 1, c;
	while (n--){
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}


// 수학적 규칙을 찾는 것이 key point!
// https://leetcode.com/problems/climbing-stairs/