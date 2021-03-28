#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
  
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define all(x) x.begin(),x.end()
#define endl '\n'
#define MOD 1000000007
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;
typedef map< ll, ll > ml;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,i,k;
    cin>>n>>k;
    
    ll p=k%n;
    
    ordered_set< ll > o;
    for(i=1;i<=n;i++){
        o.insert(i);
    }
    
    while(o.size()){
        ll r = *o.find_by_order(p);
        o.erase(r);
        if(o.size()){
            p=(p+k)%o.size();
        }
        cout<<r<<" ";
    }
   
    return 0;
}
