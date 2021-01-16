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
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
 
 
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
 
    for(i=1;i<n;i++){
        if(a[i]<a[i-1]){
            ans+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
 
    cout<<ans<<endl;
    
    return 0;
}
