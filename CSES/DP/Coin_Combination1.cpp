#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int N = 1e6 + 10;

int a[N],val[N];
int n,sum;
int ans[N];
signed main()
{
	cin >> n >> sum;
	for(int i = 0;i < n; ++i)
	{
		cin >> a[i];
	}
	
	ans[0] = 1;
	
	for(int i = 1; i <= sum; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i - a[j] >= 0)
			{
				ans[i] += ans[i - a[j]];
				ans[i] %= mod;
			}
		}
	}
	cout << ans[sum]%mod;
}
