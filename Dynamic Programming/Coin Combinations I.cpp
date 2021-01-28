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
ll power(ll a, ll b){
    if(b==1){
        return a;
    }

    ll temp = power(a,b/2);

    if(b%2==0){
        return temp*temp;
    }else{
        return temp*temp*a;
    }
}

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

    ll dp[x+1],j;
    memset(dp,0,sizeof(dp));
    dp[0]=1;

    for(i=1;i<=x;i++){
        for(j=0;j<n;j++){
            if(i>=c[j] && dp[i-c[j]]!=0){
                dp[i]+=dp[i-c[j]];
                dp[i]=dp[i]%MOD;
            }
        }
    }


    cout<<dp[x];





    return 0;
}
