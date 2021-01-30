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
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;
 
    vector< string > vect;
    
    ll i;
    for(i=0;i<n;i++){
        string temp;
        cin>>temp;
        vect.pb(temp);
    }
 
    if(vect[0][0]=='*' || vect[n-1][n-1]=='*'){     //Consider the corner case
        cout<<0<<endl;
    }else{
        ll dp[n][n],j;
 
        memset(dp,0,sizeof(dp));
 
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(vect[i][j]=='*'){
                    continue;
                }
                if(i==0 && j==0){
                    dp[i][j]=1;
                }else if(i==0){
                    dp[i][j]=dp[i][j-1];
                }else if(j==0){
                    dp[i][j]=dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                dp[i][j]=dp[i][j]%MOD;
            }
        }
 
        cout<<dp[n-1][n-1];
 
    }
 
 
 
    return 0;
}
