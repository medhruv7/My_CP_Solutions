#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    if(n<2 && k!=0)
    {
        cout << -1;
        return 0;
    }
    if(n/2 > k)
    {
        cout << -1;
    }
    else
    {
        if(n/2==0)
        {cout << 1;
        }
        else
        {
        int y = k - (n/2 - 1);
        cout << y << " " << 2*y << " ";
        y = 2*y+1;
        int temp = n-2;
        while(temp--)
        {
            cout << y << " ";
            ++y;
        }
        }
    }
    
}