//Iterative

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
const int inf = 1e17;
int ans[N];
 
signed main()
{
	int n,sum;
	cin >> n >> sum;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	ans[0] = 0;
	
	for(int i = 1; i <= sum; ++i)
	{
		ans[i] = inf;
		for(int j = 0; j < n; ++j)
		{
			if(i - a[j] >= 0)
			{
				ans[i] = min(ans[i],ans[i - a[j]] + 1);
			}
		}
	}
	
	cout << (ans[sum] == inf?-1:ans[sum]);
  
//Recursive

#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
 
const int N = 1e6 + 10;
const int inf = 1e7;
int n,sum;
int a[N];
int val[N];
bool ready[N];
 
int solve(int sum)
{
	if(sum == 0) return 0;
	if(sum < 0) return inf;
	if(ready[sum]) return val[sum];
	
	val[sum] = inf;
	for(int i = 0; i < n; ++i)
	{
		val[sum] = min(val[sum],solve(sum - a[i]) + 1);
	}
	
	ready[sum] = true;
	return val[sum];
}
 
signed main()
{
	cin >> n >> sum;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	solve(sum);
	cout << (val[sum] == inf ? -1 : val[sum]);
}
