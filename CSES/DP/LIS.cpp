#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
	int n,x;
	cin >> n;
	vector<int> a;
	while(n--)
	{
		cin >> x;
		auto it = lower_bound(a.begin(),a.end(),x);
		if(it == a.end())a.push_back(x);
		else *it = x;
	}
	
	cout << a.size() << '\n';
}
