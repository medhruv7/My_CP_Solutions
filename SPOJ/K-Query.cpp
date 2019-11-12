#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vvi vector<vector<int>> 
#define vi vector<int> 
#define vpii vector<pair<int,int>> 
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define ffor(i,n) for(int i = 0; i < n; ++i)
const int N = 3e5 + 10; 
int n;
int t[2*N];

// cin t[i + n]

void build()
{
    for(int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
}

// change value at position p(0 indexed)

void modify(int p,int value){ 
    for(t[p += n] = value;p > 1; p >>= 1) t[p >> 1] = t[p] + t[p^1];
}

// sum is on [l,r) and l and r are 0 indexed
int query(int l,int r)
{
    int res = 0;
    for(l += n, r += n; l < r; l >>=1 , r >>= 1){
        if(l&1) res += t[l++];
        if(r&1) res += t[--r];
    }

    return res;
}

struct Query
{
    int l,r,k,id;
};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vpii a(n);
    for(int i = 0; i < n; ++i) 
    {
        cin >> a[i].ff;
        a[i].ss = i;
    }
    build();
    sort(all(a),[](auto x,auto y)
    {
        return x.ff > y.ff;
    });
    int q;
    cin >> q;
    vector<Query> qr(q);
    ffor(i,q)
    {
        cin >> qr[i].l >> qr[i].r >> qr[i].k;
        qr[i].l--;
        qr[i].id = i;
    }
    sort(all(qr),[](auto a,auto b){
        return a.k > b.k;
    });
    
    int z = 0;
    vi ans(q);
    for(int i = 0;i < q; ++i)
    {
        while(z < n && a[z].ff > qr[i].k) 
        {
            modify(a[z].ss,1LL);
            ++z;
        }
        ans[qr[i].id] = query(qr[i].l,qr[i].r);
    }
   
    for(int i = 0; i < q; ++i)
    {
        cout << ans[i] << '\n';
    }
}
