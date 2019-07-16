#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 2e5+10;
const int mod = 1e9 + 7;
vector<int> adj[N];
int vec[N];
bool vis[N];
int dfs(int root,int pre)
{
	for(auto x : adj[root])
	{
		if(x != pre)
		{
			vec[root]++;
			vec[root] += dfs(x,root);
		}
	}
	
	return vec[root];
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i < n; ++i)
	{
		int x;
		cin >> x;
		--x;
		adj[x].push_back(i);
	}
	dfs(0,-1);
	for(int i = 0; i < n; ++i){
		cout << vec[i] << " ";
	}
}

