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
    
    ll x,y;
    cin>>x>>y;

    ll dp[x+1][y+1];
    ll i,j,k,temp;

    for(i=0;i<=x;i++){
        for(j=0;j<=y;j++){
            if(i==j){
                dp[i][j]=0;
            }else{
                temp=LONG_MAX;
                for(k=1;k<i;k++){
                    temp=min(temp,dp[k][j]+dp[i-k][j]+1);
                }
                for(k=1;k<j;k++){
                    temp=min(temp,dp[i][k]+dp[i][j-k]+1);
                }
                dp[i][j]=temp;
            }
        }
    }

    cout<<dp[x][y];




    return 0;
}
