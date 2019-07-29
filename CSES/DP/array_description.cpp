#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5+10;
const int mod = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
	{
		cin >> a[i];
	}
	
	vector<vector<int>> dp(n,vector<int>(m+1));
	
	//~ // dp[i][j] is the number of arrays possible upto ith element with ith element's value = j
	
	if(a[0] != 0) dp[0][a[0]] = 1;
	else
	{
		for(int i = 1; i <= m ; ++i)
		{
			dp[0][i] = 1;
		}
	}
	for(int i = 1; i < n; ++i)
	{
		if(a[i] != 0)
		{
			if(a[i] != 1)
			(dp[i][a[i]] += dp[i-1][a[i]-1])%=mod;
			(dp[i][a[i]] += dp[i-1][a[i]])%=mod;
			if(a[i] != m)
			(dp[i][a[i]] += dp[i-1][a[i]+1])%=mod;
			
		}
		else
		{
			for(int j = 1;j <= m; ++j)
			{
				(dp[i][j] += dp[i-1][j])%=mod;
				if(j != 1)
				(dp[i][j] += dp[i-1][j-1])%=mod;
				if(j != m)
				(dp[i][j] += dp[i-1][j+1])%=mod;

				//~ cout << dp[i][j] << " ";
			}
		}
		//~ cout << '\n';
	}
	
	int ans = 0;
	
	
	if(a[n-1] != 0) cout << ((dp[n-1][a[n-1]])%=mod);
	else
	{
		for(int i = 1; i <= m; ++i)
		{
			(ans += dp[n-1][i])%=mod;
		}
		cout << ans%mod;
	}
}

