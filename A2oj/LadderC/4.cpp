#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,currmax = 0;
ll a[5005],b[50005];
int main()
{
	cin >> n;
	vector<pair<ll,ll>> ans(n);
	for(ll i=0;i<n;i++)
	{
		cin >> a[i] >> b[i];
		ans[i] = {a[i],b[i]};
	}
	
	sort(ans.begin(),ans.end());
	for(ll i=0;i<n-1;i++)
	  {
		  if(ans[i].second>=currmax)
		  {
			  currmax = ans[i].second;
		  }
		  else
		  {
			  currmax = ans[i].first;
		  }
	  }
	if(ans[n-1].second>=currmax)cout << ans[n-1].second;
	else cout << ans[n-1].first;
}
