// This is simple dearrangement formula
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
    cout.tie(NULL);

    ll i;
    ll n;

    cin>>n;

    if(n==1){
        cout<<0;
        exit(0);
    }

    ll d[n+1];
    d[0]=0;
    d[1]=0;
    d[2]=1;

    for(i=3;i<=n;i++){
        d[i]=((d[i-1]+d[i-2])%MOD)*(i-1)%MOD;
    }

    cout<<d[n]<<endl;

    return 0;
}
