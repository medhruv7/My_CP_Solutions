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

const int mxn = 5e4 + 10;

struct dat{
    int ans,sum,pref,suf;
};

dat make_set(int val){
    dat res;
    res.ans = res.sum = res.pref = res.suf = val;
    return res;
}

dat combine(dat l,dat r){
    dat res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref,l.sum + r.pref);
    res.suf = max(r.suf,r.sum + l.suf);
    res.ans = max({l.ans,r.ans,l.suf + r.pref});
    return res;
}
vector<dat> t(4*mxn);
vi a;

void build(int v,int tl,int tr){
    if(tl == tr){
        t[v] = make_set(a[tl]);
    }else{
        int tm = (tl + tr)/2;
        build(2*v,tl,tm);
        build(2*v + 1,tm + 1,tr);
        t[v] = combine(t[2*v],t[2*v + 1]);
    }
}


void update(int v,int tl,int tr,int pos,int val){
    if(tl == tr){
        t[v] = make_set(val);
    }else{
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2*v,tl,tm,pos,val);
        }else{
            update(2*v + 1,tm + 1,tr,pos,val);
        }
        t[v] = combine(t[2*v],t[2*v + 1]);
    }
}

dat query(int v,int tl,int tr,int l,int r){
    if(l > r){
        dat res;
        res.sum = 0;
        res.pref = res.suf = res.ans = -1e6;
        return res;
    }
    if(l == tl && r == tr){
        return t[v];
    }else{
        int tm = (tl + tr)/2;
        if(l > tm){
            return query(2*v + 1,tm + 1,tr,max(tm + 1,l),r);
        }else if(r <= tm){
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
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        a.assign(n,0);
        ffor(i,n)cin >> a[i];
        build(1,0,n - 1);
        int m;
        cin >> m;
        while(m--){
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            --x1,--y1,--x2,--y2;
            // if no overlap
            if(x2 > y1){
                cout << (query(1,0,n - 1,x1,y1).suf + query(1,0,n - 1,y1 + 1,x2 - 1).sum + query(1,0,n - 1,x2,y2).pref) << '\n';
            }else{
                int ans;
                ans = query(1,0,n - 1,x1,x2 - 1).suf + query(1,0,n - 1,x2,y2).pref;
                ans = max(ans,query(1,0,n - 1,x2,y1).suf + query(1,0,n - 1,y1 + 1,y2).pref);
                ans = max(ans,query(1,0,n - 1,x2,y1).ans);
                cout << ans << '\n';
            }        
        }
    }
}
