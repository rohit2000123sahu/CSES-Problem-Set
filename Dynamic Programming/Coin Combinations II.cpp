#include <bits/stdc++.h>
using namespace std;
 
#define ll int
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
    
    ll n,x;
    cin>>n>>x;
 
    ll c[n];
    ll i;
 
    for(i=0;i<n;i++){
        cin>>c[i];
    }
 

    ll dp[n+1][x+1],j;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
 
    for(i=0;i<=n;i++){
        for(j=0;j<=x;j++){
            if(j==0){
                dp[i][j]=1;
            }else if(i==0){
                dp[i][j]=0;
            }else{
                ll with_coin=0;
                ll without_coin=0;
 
                if(j-c[i-1]>=0){
                    with_coin=dp[i][j-c[i-1]];
                }
                without_coin = dp[i-1][j];
 
                dp[i][j]=(with_coin+without_coin)%MOD;
            }
        }
    }
 

    cout<<dp[n][x];
 
 
    return 0;
}
