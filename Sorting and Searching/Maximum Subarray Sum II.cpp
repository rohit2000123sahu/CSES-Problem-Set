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
typedef vector< pl > vpl;
typedef map< ll, ll > ml;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    ll n,a,b;
    cin>>n>>a>>b;

    ll arr[n+1];
    ll i;

    for(i=1;i<=n;i++){
        cin>>arr[i];
    }

    ll prefix[n+1]={0};

    for(i=1;i<=n;i++){
        prefix[i]=arr[i]+prefix[i-1];
    }

    multiset< ll > m;

    ll ans=LONG_LONG_MIN;

    for(i=a;i<=n;i++){
        if(i>b){
            m.erase(m.find(prefix[i-b-1]));
        }
        m.insert(prefix[i-a]);
        ans=max(ans,prefix[i]-*m.begin());
    }

    cout<<ans<<endl;


    return 0;
}
