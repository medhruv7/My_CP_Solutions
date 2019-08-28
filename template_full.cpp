#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define all(a) a.begin(),a.end()
#define sz(x) ((int)x.size())
#define ff first 
#define ss second 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef map<int,int> mii;
typedef map<char,int> mci;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpii;
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_ms;
