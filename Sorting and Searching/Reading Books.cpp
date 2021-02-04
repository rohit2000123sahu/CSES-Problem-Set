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

    ll i,a[n];
    ll sum=0;

    for(i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    sort(a,a+n);
    if(a[n-1]>=sum-a[n-1]){
        cout<<2*a[n-1];
    }else{
        cout<<sum;
    }

    return 0;
}
