// Greedy always select the one which finishes early
#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 1e5+10;
const int mod = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,x,y,c = 0, s = 0;
	cin >> n;
	vector<tuple<int,int>> a(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		a[i] = {y,x};
	}
	sort(a.begin(),a.end());
	
	for(auto z : a)
	{
		tie(y,x) = z;
		if(x >= s) s = y, c++;
	}
	
	cout << c << '\n';
}
