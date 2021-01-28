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
#define INF 10000000000
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    ll dp[n+1],i;
    dp[0]=0;
    memset(dp,0,sizeof(dp));
    ll num;
    ll minimum;

    for(i=1;i<=n;i++){
        num=i;
        minimum=INF;
        while(num!=0){
            if(num%10!=0){          //To handle the corner case
                minimum=min(minimum,dp[i-(num%10)]);
            }
            num=num/10;
        }
        dp[i]=1+minimum;
    }


    cout<<dp[n];

    return 0;
}
