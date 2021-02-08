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

// ll solve(ll i, ll j){
//     if(i>j){
//         return 0;
//     }
//     if(i==j){
//         return vect[i];
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }

//     dp[i][j]=max(vect[i]+min(solve(i+1,j-1),solve(i+2,j)),vect[j]+min(solve(i+1,j-1),solve(i,j-2)));

//     return dp[i][j];
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    ll dp[n+5][n+5];
    vl vect;    

    ll i,temp;
    for(i=0;i<n;i++){
        cin>>temp;
        vect.pb(temp);
    }

     memset(dp,0,sizeof(dp));

    for(i=0;i<n;i++){
        dp[i][i]=vect[i];
    }

    ll len,j;

    for(len=2;len<=n;len++){
        for(i=0;i<n-len+1;i++){
            j=i+len-1;
            dp[i][j]=max(vect[i]+min(dp[i+1][j-1],dp[i+2][j]),vect[j]+min(dp[i+1][j-1],dp[i][j-2]));
        }
    }

    cout<<dp[0][n-1];

    return 0;
}
