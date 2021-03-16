// We can solve this problem using DP
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
    
    ll n,m;
    cin>>n>>m;

    ll i,j;
    ll mat[n+1][n+1];

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            char temp;
            cin>>temp;
            if(temp=='.'){
                mat[i][j]=0;
            }else{
                mat[i][j]=1;
            }
        }
    }

    ll dp[n+1][n+1];

    memset(dp,0,sizeof(dp));

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i][j];
        }
    }    

    while(m--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        cout<<dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1]<<endl;
    }

    return 0;
}
