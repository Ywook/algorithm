#include <stdio.h>
#define max(a,b) ((a)>(b) ? (a):(b))

int p[1004];
int dp[1004];
int main(int argc, char const *argv[])
{
	int n, i, j;
	scanf("%d", &n);

	for(i = 1; i <= n ; i++){
		scanf("%d", &p[i]);
	}

	for(i = 1; i <= n; i++){
		for(j = 1; j <= i ; j++){
			dp[i] = max(dp[i], dp[i-j] + p[j]);
		}
	}
	printf("%d\n", dp[n]);

	return 0;
}