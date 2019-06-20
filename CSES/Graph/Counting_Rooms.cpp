#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define vi vector<int>
#define vpii vector<pair<int,int>> 
#define all(V) V.begin(),V.end()
#define mpii map<int,int> 
#define mpci map<char,int> 
#define fi first
#define si second

const int N = 1e3+10;
const int mod = 1e9 + 7;

char a[N][N];
bool vis[N][N];

int n,m;

int ans = 0;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool check(int r, int c)
{
	if(r < n && r >= 0 && c < m && c >= 0 && a[r][c] != '#')
	{
		return true;
	}
	return false;
}

void dfs(int r,int c)
{	
	vis[r][c] = true;
	
	for(int i = 0; i < 4; ++i)
	{
		if(check(r+dx[i],c+dy[i]) && !vis[r + dx[i]][c + dy[i]])
		{
			dfs(r+dx[i],c+dy[i]);
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m ; ++j)
		{
			cin >> a[i][j];
		}
	}
	
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0;j < m; ++j)
		{
			if(!vis[i][j] && a[i][j] != '#')
			{
				ans++;
				dfs(i,j);
			}
		}
	}
	
	cout << ans;
}

