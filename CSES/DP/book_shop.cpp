#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
 
const int N = 1e5+10;
const int mod = 1e9 + 7;
 
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,x;
	cin >> n >> x;
	vector<int> wt(n),val(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> wt[i];
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> val[i];
	}
	
	// dp[i][j] the max value i can obtain with exactly first i elements and j weight available in my knapsack
	vector<vector<int>> dp(2,vector<int>(x+1,0));
 
		for(int j = 1; j <= n; ++j)
		{
			for(int i = 1;i <= x; ++i)
			{
				if(wt[j-1] > i)
				{
					dp[1][i] = dp[0][i];
				}
				else
				{
					dp[1][i] = max(dp[0][i],dp[0][i-wt[j-1]] + val[j-1]);
				}
				//~ cout << dp[1][i] << " ";
			}
			dp[0] = dp[1];
		}
		cout << '\n';
		
	cout << dp[0][x];
}
