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
 
struct data1{
    int sum,pref,suff,ans;
};
 
const int mxn = 50010;
vector<data1> t(4*mxn);
vi a;
 
data1 combine(data1 l, data1 r){
    data1 res;
    res.sum = l.sum + r.sum;
    res.suff = max(r.suff,l.suff + r.sum);
    res.pref = max(l.pref,l.sum + r.pref);
    res.ans = max({l.ans,r.ans,l.suff + r.pref});
    return res;
}
 
data1 make_set(int val){
    data1 res;
    res.sum = res.suff = res.pref = res.ans = val;
    return res;
}
 
void build(int v,int tl, int tr){
    if(tl == tr){
        t[v] = make_set(a[tl]);
    }else{
        int tm = (tl + tr)/2;
        build(2*v,tl,tm);
        build(2*v + 1,tm + 1,tr);
        t[v] = combine(t[2*v],t[2*v + 1]);
    }
}
 
data1 query(int v,int  tl,int tr,int l,int r){
    if(l > r) return make_set(0);
    if(l == tl && r == tr){
        return t[v];
    }else{
        int tm = (tl + tr)/2;
        if(l > tm){
            return query(2*v + 1,tm + 1,tr,max(tm + 1,l),r);
        }
        else if(r <= tm){
            return query(2*v,tl,tm,l,min(r,tm));
        }else{
            return combine(query(2*v,tl,tm,l,tm),query(2*v + 1,tm + 1,tr,tm + 1,r));
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    mt19937_64 rngl(chrono::steady_clock::now().time_since_epoch().count());
    
    int n;
    cin >> n;
 
    a.resize(n);
    ffor(i,n)cin >> a[i];
 
    build(1,0,n - 1);
    int qr;
    cin >> qr;
    while(qr--){
        int x,y;
        cin >> x >> y;
        --x, --y;
        data1 res = query(1,0,n - 1,x,y);
        cout << res.ans << '\n';
    }
} 
