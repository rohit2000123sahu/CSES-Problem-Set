#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S secondP
#define PI 3.1415926535897932384626
#define all(x) x.begin(),x.end()
#define endl '\n'
#define MOD 1000000007
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;
typedef map< ll, ll > ml;

vl adj[200005];
ll n;
ll ans;

ll diameter(ll i, ll par){
    ll m1=0;
    ll m2=0;
    for(auto c: adj[i]){
        if(c==par){
            continue;
        }
        ll temp=diameter(c,i)+1;
        if(temp>=m1){
            m2=m1;
            m1=temp;
        }else if(temp>=m2){
            m2=temp;
        }
    }

    ans=max(ans,m1+m2);

    // cout<<i<<" "<<m1<<" "<<m2<<endl;

    return max(m1,m2);

    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    ll i;
    ll a,b;

    ans=0;

    for(i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    diameter(1,-1);

    cout<<ans<<" ";
    
    

    return 0;
}
