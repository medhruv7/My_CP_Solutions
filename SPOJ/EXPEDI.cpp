#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<pair<ll,ll>> a(n);
        for(ll i=0;i<n;i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        ll count = 0;
        ll l,p;
        cin >> l >> p;
        for(ll i=0;i<n;i++)
        {
            a[i].first = l-a[i].first;
        }
        bool ok = true;
        sort(a.begin(),a.end());
        priority_queue<ll> pq;
        ll curr = 0;
        for(ll i=0;i<n;i++)
        {
            //cout << i << " ";
            p-= (a[i].first - curr);
            curr = a[i].first;
            //cout << p << " ";
            if(p>=0)
            {
                pq.push(a[i].second);
            }
            else
            {
                while(p<0)
                {
                    if(!pq.empty())
                     {   //cout << p << " ";
                    //     cout << pq.top();
                        p+=pq.top();
                        count++;
                        pq.pop();
                    }
                    else
                    {
                        ok = false;
                        count = -1;
                        //cout << i << " ";
                        break;
                    }
                    
                }
                pq.push(a[i].second);
            }
           
            if(ok == false)
            break;
        }

         //cout << " " << p;
        if(ok == true)
        {
            p-= (l-a[n-1].first);
           // cout << " " << p;
           
            if(p<0)
            {
                while(p<0)
                {
                    if(!pq.empty())
                    {
                        p+=pq.top();
                        count++;
                        pq.pop();
                    }
                    else
                    {
                        ok = false;
                        count = -1;
                    }
                }
            }
            
        }

        cout << count << endl;
    }
}
