#include <stdio.h>
#define min(a,b) (((a) < (b)) ? (a):(b))

int dp[1000005];
int main(int argc, char const *argv[])
{
	int n, i;

	scanf("%d", &n);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1; 
	
	for(i = 4; i <= n ; i++){
		if(i%3 == 0 && i%2 == 0){
			dp[i] = min(1+dp[i/3], 1+ dp[i/2]);
			dp[i] = min(dp[i], 1+dp[i-1]);
		}else if(i%3 == 0){
			dp[i] = min(1+dp[i-1], dp[i/3] + 1);
		}else if(i%2 == 0){
			dp[i] = min(1+dp[i-1], dp[i/2] + 1);
		}else{
			dp[i] = dp[i-1]+1;
		}
	}
	printf("%d\n", dp[n]);
	/* code */
	return 0;
}