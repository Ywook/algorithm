#include <iostream>
using namespace std;
long dp[20];

int main(int argc, char const *argv[])
{
	int t,n;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;

	for(int i = 5; i < 11; i++) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	while(t--){
		cin >> n;
		cout<<dp[n]<<endl;
	}
	return 0;
}