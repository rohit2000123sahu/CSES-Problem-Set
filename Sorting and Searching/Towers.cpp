#include <bits/stdc++.h>
using namespace std;

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
typedef map< ll, ll > ml;
typedef vector< pl > vpl;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    ll a[n];
    ll i;

    for(i=0;i<n;i++){
        cin>>a[i];
    }

    ll ans=0;

    multiset< ll > s;

    for(i=0;i<n;i++){
        auto itr = s.upper_bound(a[i]);
        if(itr==s.end()){
            s.insert(a[i]);
            ans++;
        }else{
            s.erase(itr);
            s.insert(a[i]);
        }
    }

    cout<<ans<<endl;

    return 0;
}
