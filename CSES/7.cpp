#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(ll i=1;i<=n;i++)
	{
		cout << (ll)((i*i)*(i*i-1)/2 - 2*((i-2)*(i-1) + (i-1)*(i-2)));
		cout << endl;
	}
	
}
