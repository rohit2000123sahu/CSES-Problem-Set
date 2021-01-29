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
ll power(ll a, ll b){
    if(b==1){
        return a;
    }

    ll temp = power(a,b/2);

    if(b%2==0){
        return temp*temp;
    }else{
        return temp*temp*a;
    }
}

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

    sort(a,a+n);

    ll prefix[n],suffix[n];

    prefix[0]=a[0];
    suffix[n-1]=a[n-1];

    for(i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }

    for(i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]+a[i];
    }

    ll ans=LONG_LONG_MAX;

    for(i=n/2;i<n/2+1;i++){     //We need to check at n/2 only.
        ans=min(ans,a[i]*(i)-prefix[i-1]+suffix[i+1]-a[i]*(n-i-1));
    }

    cout<<ans<<endl;




    return 0;
}
