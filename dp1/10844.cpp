#include <iostream>
#include <vector>

using namespace std;

long long dp[104][11];
int main(int argc, char const *argv[])
{
	/* code */
	int n, i, j;
	cin >> n;

	for(i = 1 ; i < 10; i++){
		dp[1][i] = 1;
	}

	for(i = 2 ; i <= n ; i++){
		dp[i][0] = dp[i-1][1];
		for(j = 1; j <= 9; j++){
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
		}
	}

	for(i = 0; i<= 9; i++){
		dp[n][10] = (dp[n][10] + dp[n][i])%1000000000;
	}
	cout<<dp[n][10]<<endl;

	return 0;
}