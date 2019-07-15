#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,x;
	cin >> n >> x;
	deque<int> dq(n);
	for(int i =0 ; i < n; ++i)
	{
		cin >> dq[i];
	}
	sort(dq.begin(),dq.end());
	int ans = 0;
	while(!dq.empty())
	{
		if(dq.size() == 1)
		{
			ans++;
			dq.pop_back();
			continue;
		}
		if(dq[0] + dq[dq.size()-1] <= x)
		{
			dq.pop_back();
			dq.pop_front();
		}
		else
		{
			dq.pop_back();
		}
		ans++;
	}
	cout << ans;
}
