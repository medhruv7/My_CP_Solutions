#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5+10;
const int mod = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,x;
	cin >> n >> x;
	vector<int> a(n);
	map<int,pair<int,bool>> mp;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if(mp[x - a[i]].second)
		{
			cout << i + 1 << " " << mp[x - a[i]].first + 1;
			return 0;
		}
		mp[a[i]].first = i;
		mp[a[i]].second = true;
	}
	
	cout << "IMPOSSIBLE";
}

