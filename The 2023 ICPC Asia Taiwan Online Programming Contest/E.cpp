#a, b, c = map(int, input().split())


a, b, m = map(int, input().split());
a = a % m;
dp = {}

def Cal(n):
	if n == 1:
		return a;
	if n in dp:
		return dp[n];
	if n % 2 == 0:
		Ans = Cal(n // 2) * Cal(n // 2) - 2 + m;
		dp[n] = Ans % m;
		return dp[n];
	if n % 2 == 1:
		Ans = Cal(n // 2) * Cal(n // 2 + 1) - a + m;
		dp[n] = Ans % m;
		return dp[n];

print(Cal(b));


