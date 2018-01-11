#include <stdio.h>

int dp[1005];
int main(int argc, char const *argv[])
{
	int n, i;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for(i = 4; i <= n ; i++){
		dp[i] = (dp[i-1] + dp[i-2]*2)%10007;
	}
	printf("%d\n", dp[n]);
	/* code */
	return 0;
}