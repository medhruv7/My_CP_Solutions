#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 500005;
int n;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int cost[N];
int m;
const int MOD = 1000000007;
vector<int> g[N],gr[N];
vector<bool> used;
vector<int> order,component;

bool cmp(int a,int b)
{
    return cost[a]<cost[b];
}
void dfs1(int v)
{
    used[v] = true;
    for(auto x:g[v])
    {
        if(!used[x])
        {
            dfs1(x);
        }
    }
    order.push_back(v);
}

void dfs2(int v)
{
    used[v] = true;
    component.push_back(v);
    for(auto x:gr[v])
    {
        if(!used[x])
        dfs2(x);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;++i)
    cin >> cost[i];
    cin >> m;
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin >> a >> b;
        --a,--b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    used.assign(n,false);
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        dfs1(i);
    }
    used.assign(n,false);
    ll sum = 0;
    ll ways = 0;
    ll ans = 1;
    for(int i=0;i<n;++i)
    {
        int v = order[n-1-i];
        if(!used[v])
        {
            dfs2(v);
            sort(component.begin(),component.end(),cmp);
            //cout << "COMPONENT";
            // for(auto x:component)
            // cout << x << " ";
            auto it = component.begin();
            while(cost[*it] == cost[*component.begin()])
            {
                ways++;
                it++;
                if(it==component.end())
                break;
            }
            ways %= MOD;
            ans = (ans*ways)%MOD;
            sum += cost[component[0]];
            component.clear();
            ways = 0;
            //cout << endl;
        }
    }
    cout << sum << " " << ans;
}
