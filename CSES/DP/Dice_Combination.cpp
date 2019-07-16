#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e6+10;
const int mod = 1e9 + 7;
int ready[N];
int val[N];
int solve(int n)
{
	if(n == 0)
	return 1;
	if(n < 0)
	return 0;
	if(ready[n])
	return val[n];
	
	val[n] = solve(n-1) + solve(n-2) + solve(n-3) + solve(n-4) + solve(n-5) + solve(n-6);
	val[n] %= mod;
	ready[n] = true; 
	
	return val[n];
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	solve(n);
	cout << val[n]%mod;
}

// Iterative Solution
#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e6+10;
const int mod = 1e9 + 7;
int ready[N];
int val[N];

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	val[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		for(auto x:{1,2,3,4,5,6})
		{
			if(i - x >= 0)
			{
				val[i] += val[i - x];
			}
			val[i] %= mod;
		}
	}
	cout << val[n]%mod;
}

