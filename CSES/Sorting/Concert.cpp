
// Solution 1 
#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5+10;
const int mod = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	multiset<int> tick; 
	vector<int> cust(m);
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		tick.insert(x);
	}
	for(int i = 0 ; i < m; ++i)
	{
		cin >> cust[i];
		if(tick.size() == 0) 
		{cout << -1;
		 continue;
		}
		auto it = tick.upper_bound(cust[i]);
		if(it == tick.begin())
		{
			cout << -1 << '\n';
			continue;
		}
		--it;
		if(*it <= cust[i])
		{
			cout << *it << '\n';
			tick.erase(tick.find(*it));
		} 
		else
		{
			cout << *it << '\n';
			cout << -1 << '\n';
		}
	}
}

// Better Solution
multiset<int,greater<int>> tick;
vector<int> cust(m);
for(int i = 0 ;i < n; ++i)
{
  int x;
  cin >> x;
  tick.insert(x);
}
for(int i = 0 ; i < m; ++i)
{
  auto it = tick.lower_bound(cust[i]);
  if(it == tick.end())
  {
    cout << -1 << '\n';
    continue;
  }
  cout << *it << '\n';
  tick.erase(it);
}
