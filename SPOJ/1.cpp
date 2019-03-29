#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll N = 100001;
vector<ll> adj[N];
vector<bool> visited(N,false);
queue<ll> q;
vector<bool> used(N);


void dfs(ll u)
{
    if(visited[u]) return;
    visited[u] = true;
    cout << u << " ";
    for(auto x:adj[u])
    {
        dfs(x);
    }
}

void bfs(ll u)
{
    q.push(u);
    used[u] = true;
    while(!q.empty())
    {
        ll v = q.front();
        cout << v << " ";
        q.pop();
        for(auto x:adj[v])
        {
            if(!used[x])
            {
            used[x] = true;
            q.push(x);
            }
        }
    }
}
int main()
{
    ll t;
    cin >> t;
    for(ll z=1;z<=t;z++)
    {
        ll n;
        cin >> n;        

        for(ll i=0;i<n;i++)
        {
            ll u;
            cin >> u;
            ll m;
            cin >> m;
            while(m-->0)
            {
                ll v;
                cin >> v;
                adj[u].push_back(v);
            }
        }
        cout << "graph " << z << endl;
        while(true)
        {
        ll type;
        ll u;
        cin >> u >> type;
        if(u==0 && type==0)
        {
            break;
        }
        if(type==0)
        { 
           dfs(u); 
           
        }
        else if(type==1)
        {
          bfs(u);
        }
        visited.assign(N,false);
        used.assign(N,false);
        cout << endl;
        }

        for(ll i=1;i<=n;i++)
        {
            adj[i].clear();
        }
    }
}