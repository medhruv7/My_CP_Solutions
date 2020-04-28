//dhruv
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ffor(i,n) for(int i = 0;i < (n); ++i)
#define fro(i,j,n) for(int i = (j);i < (n); ++i)
#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>
#define ff first
#define ss second

const int mod = 1e9 + 7;

int binpow(int a,int b){
	int res = 1;
	while(b){
		if(b&1){
			res = (res*a)%mod;
		}
		b >>= 1;
		a = (a*a)%mod;
	}
	return res;
}
int add(int a,int b){
	return (a + b)%mod;
}
int sub(int a,int b){
	return add(a,mod - 1);
}
int mul(int a,int b){
	return (a*b)%mod;
}
int inv(int a){
	return binpow(a,mod - 2);
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        int ass[n][n];
        ffor(i,n){
            ffor(j,n){
                cin >> ass[i][j];
            }
        }

        int ways = 0;
        vector<int> dp((1<<n));
        // total configuration when nothing is assigned to anyone
        dp[0] = 1;
        for(int i = 0;i < (1<<n); ++i){
            // already considered children
            int done = __builtin_popcount(i);
            for(int j = 0;j < n; ++j){
                if(!((1<<j)&i) && (ass[done][j] == 1)){
                    dp[i|(1<<j)] += (dp[i]);
                }
            }
        }
        cout << dp[(1<<n) - 1] << '\n';
    }
}		
