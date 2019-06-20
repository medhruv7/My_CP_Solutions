#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define vi vector<int>
#define vpii vector<pair<int,int>> 
#define all(V) V.begin(),V.end()
#define mpii map<int,int> 
#define mpci map<char,int> 
#define vvi vector<vi>
#define fi first
#define si second
#define pii pair<int,int>
#define pb(V) push_back(V)
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define mp(a,b) make_pair(a,b)
#define mt(a,b,c) make_tuple(a,b,c)

const int N = 1e5+10;
const int mod = 1e9 + 7;

vector<vector<char>> a;
pii s1,e1;
vvi b;
int n,m;


void bfs(int r, int c, int dist)
{
	queue<tuple<int,int,int>> q;
	q.push(mt(r,c,0));
	while(!q.empty())
	{
		int i,j,k;
		tie(i,j,k) = q.front();
		q.pop();
		if(b[i][j] != -1)
		{
			continue;
		}		
		b[i][j] = k;
		if(i == e1.fi && j == e1.si)
		{
			string ans;
			cout << "YES\n" << b[i][j] << '\n';
			while(i != s1.fi || j != s1.si)
			{
				if(i < n-1 && b[i+1][j] == k-1)
				{
					ans.pb('U');
					++i;
				}
				else if(i > 0 && b[i-1][j] == k-1)
				{
					ans.pb('D');
					--i;
				}
				else if(j > 0 && b[i][j-1] == k-1)
				{
					ans.pb('R');
					--j;
				}
				else if(j < m-1 && b[i][j+1] == k-1)
				{
					ans.pb('L');
					++j;
				}
				--k;
			}
			reverse(ans.begin(),ans.end());
			cout << ans << '\n';
			return;
		}
		
		if(i > 0 && a[i-1][j]!='#' && b[i-1][j] == -1)
		{
			q.push({i-1,j,k+1});
		}
		if(i < n - 1 && a[i+1][j]!='#' && b[i+1][j] == -1)
		{
			q.push({i+1,j,k+1});
		}
		if(j > 0 && a[i][j-1]!='#' && b[i][j-1] == -1)
		{
			q.push({i,j-1,k+1});
		}
		if(j < m-1 && a[i][j+1]!='#' && b[i][j+1] == -1)
		{
			q.push({i,j+1,k+1});
		}
	}
	
	cout << "NO\n";
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	a.resize(n);
	b.resize(n);
	for(int i = 0;i < n; ++i)
	{
		a[i].resize(m);
		b[i].resize(m,-1);
		
		for(int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
			if(a[i][j] == 'A')
			{
				s1.fi = i;
				s1.si = j;
			}
			else if(a[i][j] == 'B')
			{
				e1.fi = i;
				e1.si = j;
			}
		}
	}
	
	//~ for(int i=0;i<n;++i)
	//~ {
		//~ for(int j=0;j<m;++j)
		//~ {
			//~ cout << a[i][j] << " " << b[i][j];
		//~ }
		//~ cout << '\n';
	//~ }
	
	
	//~ cout << s1.fi << " " << s1.si << " ";
	bfs(s1.fi,s1.si,0);
}

