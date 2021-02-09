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
 
ll n,m;
vl vect;
ll dp[100001][101];
 
ll solve(ll i, ll value){
    if(i<0){            // Base case condition
        return 1;
    }
    if(i!=n-1 && vect[i]!=0  && abs(vect[i]-vect[i+1])>1){    // If vect[i]!=0 then we need to check whether the array is possible or not
        return 0;
    }
    if(dp[i][value]!=-1){         // Memoization
        return dp[i][value];
    }
    ll ans=0;
    if(vect[i]==0){               // If vect[i]==0 then we have to check for all the possible values of m
        ll j;
        for(j=1;j<=m;j++){
            if(i!=n-1 && abs(vect[i+1]-j)>1){
                continue;
            }
            vect[i]=j;
            ans+=solve(i-1,j);    // Checking all the possilbe values
            ans=ans%MOD;
        }
        vect[i]=0;
    }else{
        ans+=solve(i-1,vect[i]);
        ans=ans%MOD;
    }
    dp[i][value]=ans;
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>m;
    ll temp,i;
 
    memset(dp,-1,sizeof(dp));
 
    for(i=0;i<n;i++){
        cin>>temp;
        vect.pb(temp);
    }
 
    cout<<solve(n-1,0)<<endl;

 
 
    return 0;
}
