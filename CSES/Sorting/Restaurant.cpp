#include<bits/stdc++.h>

using namespace std;

#define int long long 

const int N = 1e5+10;
const int mod = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<pair<int,int>> pq;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int x,y;
		cin >> x >> y;
		pq.push({-x,1});
		pq.push({-y,-1});
	}
	
	int ans = 0;
	int cur = 0;
	while(!pq.empty())
	{
		cur += (pq.top().second == 1 ? 1 : -1);
		pq.pop();
		ans = max(ans,cur);
	}
	
	cout << ans << '\n';
}

