#include<bits/stdc++.h>
using namespace std;

// Defines 

#define all(v) v.begin(),v.end()
#define int long long
 
// Global Constants

const int N = 100;
const int mod = 1e9 + 7;
// Template Functions 

int mul(int a,int b)
{
	return (a*b)%mod;
}

int add(int a,int b)
{
	a += b;
	if(a >= mod) return a - mod;
	return a;
}

int sub(int a,int b)
{
	a -= b;
	if(a < 0) return a + mod;
	return a;
}

int binpow(int a,int b)
{
	int res = 1;
	while(b)
	{
		if(b&1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int modpow(int a, int b,int mod)
{
	int res = 1;
	while(b)
	{
		if(b&1) res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res%mod;
}
int gcd(int a, int b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}

int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}

vector<int> primes(N+1,true);

void seive()
{
	primes[0] = primes[1] = false;
	for(int i=2;(long long)i*i<=N;++i)
	{
		if(primes[i])
		{
			for(int j=i*i;j<=N;j+=i)
			{
				primes[j] = false;
			}
		}
	}
}

int modinv(int p,int mod)
{
	return modpow(p,mod-2,mod);
}
// Global Variables 


int dp[100][100];


// Functions for program

//..............................................................


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	dp[0][0] = 1;
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=n;++j)
		{
			dp[i+1][j] += (dp[i][j]);
			dp[i][j+1] += (dp[i][j]);
		}
	}	
	//cout << dp[0][1];
	cout << dp[n][n];
	
}
