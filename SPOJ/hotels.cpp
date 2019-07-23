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
	for(int i = 0; i < n; ++i) cin >> a[i];
	vector<int> dp(n+1);
	int ans = 0;
	vector<int> pre(n+1);
	for(int i = 1; i <= n; ++i)pre[i] = pre[i-1] + a[i-1];
	//~ for(int i = 0; i <= n; ++i)cout << pre[i] << " ";

	for(int i = 1; i <= n; ++i)
	{
		int lo = i, hi = n;
		while(lo < hi)
		{
			int mid = lo + (hi-lo-1)/2 + 1;
			if(pre[mid] - pre[i-1] <= m)
			{
				lo = mid;
			}
			else
			{
				hi = mid - 1;
			}
		}
		ans = max(ans,pre[hi] - pre[i-1]);
	}
	
	cout << ans;
}

