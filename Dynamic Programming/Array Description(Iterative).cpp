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

    ll n,m;
    vl vect;
    
    cin>>n>>m;
    ll temp,i,j;
    ll dp[n+1][m+1];

    memset(dp,0,sizeof(dp));

    for(i=0;i<n;i++){
        cin>>temp;
        vect.pb(temp);
    }

    for(i=0;i<n;i++){
        for(j=1;j<=m;j++){
            if(i==0){
                if(vect[i]==0 || vect[i]==j){      
                    dp[i][j]=1;
                }else{
                    dp[i][j]=0;
                }
            }else{
                if(vect[i]==0 || vect[i]==j){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
                    dp[i][j]%=MOD;
                }else{
                    dp[i][j]=0;
                }
            }
        }
    }

    ll ans=0;

    for(i=1;i<=m;i++){
        ans+=dp[n-1][i];
        ans%=MOD;
    }

    cout<<ans<<endl;

    return 0;
}
