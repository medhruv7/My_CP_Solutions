#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll x,y;
		cin >> y >> x;
		if(x==y)
		{
			cout << (ll)(x*(x-1)+1);
		}
		else
		{
			if(x>y)
			{
				if(x%2==0)
				cout << (ll)((x*(x-1)+1)-(x-y));
				else
				cout << (ll)((x*(x-1)+1)+(x-y));
			}
			else
			{
				if(y%2==0)
				cout << (ll)((y*(y-1)+1)+(y-x));
				else
				cout << (ll)((y*(y-1)+1)-(y-x));
			}
		}
		
		cout << endl;
	}
}
