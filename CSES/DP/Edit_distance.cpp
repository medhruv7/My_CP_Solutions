#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main()
{
    string s1,s2;
    cin >> s1 >> s2;
    int n  = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    // dp[i][j] -> edit distance b/w s1[i] and s2[j]
    for(int i = 0 ; i <= n; ++i)
    {
        for(int j = 0; j <= m; ++j)
        {
            if(i == 0)
            dp[i][j] = j;

            else if(j == 0)
            dp[i][j] = i;

            else if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }

            else
            {
                dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
            }
            
        }
    }

    cout << dp[n][m];
}
