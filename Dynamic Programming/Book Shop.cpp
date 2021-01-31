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
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;
 
ll n;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll x,i;
    cin>>n>>x;
 
    ll price[n];
    ll pages[n];
 
    for(i=0;i<n;i++){
        cin>>price[i];
    }
 
    for(i=0;i<n;i++){
        cin>>pages[i];
    }
 
    
    ll dp[n+1][x+1];
 
    ll j;
 
    for(i=0;i<=n;i++){
        for(j=0;j<=x;j++){
            if(i==0 || j==0){       // Left with no money or no book
                dp[i][j]=0;
            }else{
                dp[i][j]=dp[i-1][j];
                if(j>=price[i-1]){
                    dp[i][j]=max(dp[i][j],pages[i-1]+dp[i-1][j-price[i-1]]);
                }
            }
        }
    }
 
    cout<<dp[n][x];
 
 
    return 0;
}
