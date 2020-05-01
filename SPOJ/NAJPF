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

int ppow[1000001];
const int p = 31;
const int m = 1e9 + 9;
void pre(){
    ppow[0] = 1;
    for(int i = 1;i <= 1000000; ++i){
        ppow[i] = (ppow[i - 1]*p)%m;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int tc;
    cin >> tc;
    pre();
    while(tc--){
        string text,patt;
        cin >> text >> patt;
        int hp = 0;
        vector<int> hs(text.size() + 1);
        for(int i = 0;i < patt.size(); ++i){
            hp = (hp + (patt[i] - 'a' + 1)*ppow[i])%m;
        }
        for(int i = 0; i < text.size(); ++i){
            hs[i + 1] = (hs[i] + (text[i] - 'a' + 1)*ppow[i])%m;
        }
        vector<int> pos;
        // search
        int ans = 0;
        for(int i = 0;i + patt.size() - 1 < text.size(); ++i){
            int cur_hash = (hs[i + patt.size()] + m - hs[i])%m;
            if(cur_hash == hp*ppow[i]%m){
                ans++;
                pos.push_back(i);
            }
        }
        if(pos.size() == 0){
            cout << "Not Found\n";
        }else{
            cout << pos.size() << '\n';
            for(auto x : pos){
                cout << x + 1 << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
