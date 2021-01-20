#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,i,j;
    cin>>n;
 
    ll dp[n+1];
 
    dp[0]=1;
 
    for(i=1;i<=n;i++){
        ll temp=0;
        for(j=1;j<=6;j++){
            if(i-j>=0){
                temp+=dp[i-j];
                temp=temp%MOD;
            }else{
                break;
            }
        }
        dp[i]=temp;
    }
 
    cout<<dp[n]<<"\n";
    
    return 0;
}
