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
    
    ll n ,m ,k;
    cin>>n>>m>>k;

    ll a[n];
    ll i,j;
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    ll b[m];
    for(i=0;i<m;i++){
        cin>>b[i];
    }

    sort(a,a+n);
    sort(b,b+m);

    ll ans=0;
    i=0;
    j=0;

    while(i<n && j<m){
        if(abs(a[i]-b[j])<=k){     
            ans++;
            i++;
            j++;
        }else if(a[i]>b[j]){
            j++;
        }else{
            i++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
