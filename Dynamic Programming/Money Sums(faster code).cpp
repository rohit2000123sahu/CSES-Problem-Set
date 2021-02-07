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
    
    ll n;
    cin>>n;

    ll a[n],i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    ll j;
    bool dp[n+1][100001];
    memset(dp,false,sizeof(dp));
    dp[0][0]=true;

    // sort(a,a+n);

    for(i=1;i<=n;i++){
        for(j=0;j<=100000;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=a[i-1]){
                dp[i][j]=dp[i][j]||dp[i-1][j-a[i-1]];
            }
        }
    }

    vl vect;
    for(i=1;i<=100000;i++){
        if(dp[n][i]){
            vect.pb(i);
        }
    }

    cout<<vect.size()<<endl;
    for(auto c: vect){
        cout<<c<<" ";
    }


    return 0;
}
