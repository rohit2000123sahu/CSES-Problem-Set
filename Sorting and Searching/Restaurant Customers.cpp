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
#define INF 10000000000
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    ll i;

    ll a[n],d[n];

    for(i=0;i<n;i++){
        cin>>a[i]>>d[i];
    }

    ll ans=0,count=0;

    sort(a,a+n);
    sort(d,d+n);

    i=0;
    ll j=0;

    while(i<n && j<n){
        if(a[i]<d[j]){
            i++;
            count++;
            ans=max(ans,count);
        }else{
            j++;
            count--;
        }
    }

    cout<<ans<<endl;




    return 0;
}
