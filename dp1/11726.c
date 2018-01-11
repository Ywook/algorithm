#include <stdio.h>

int dp[1005];

int main(int argc, char const *argv[])
{
	int n, i;
	scanf("%d", &n);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;

	for(i = 5; i <= n; i++){
		dp[i] = (dp[i-1]+dp[i-2])%10007;
	}
	printf("%d\n", dp[n]);
	return 0;
}