#include<bits/stdc++.h>
using namespace std;

void logcal(int log1[],int n)
{
    log1[1]=0;
    for(int i=2;i<=n;i++)
    log1[i] = log1[i/2]+1;
}

void precompute(int arr[],int n,int st[][25])
{
    //int st[n][25];
    for(int i=0;i<n;i++)
    st[i][0] = arr[i];

    for(int j=1;j<=25;j++)
    {
        for(int i=0;i+(1<<j)<=n;i++)
        {
            st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    int st[n][25];
    int log1[n+1] = {0};
    for(int i=0;i<n;i++)cin >> arr[i];
    precompute(arr,n,st);
    logcal(log1,n);
    // for(int i=0;i<n+1;i++)
    // cout << log1[i] << " ";
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        int s,e;
        cin >> s >> e;
        int j = log1[e-s+1];
        int min1 = min(st[s][j],st[e-(1<<j)+1][j]);
        cout << min1 << endl;
    }    
}