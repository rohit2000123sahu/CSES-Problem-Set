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
    
    ll n;
    cin>>n;

    ll sum=(n*(n+1))/2;     // We will count the number of ways we could have sum/2;

    if(sum%2!=0){
        cout<<"0"<<endl;
        exit(0);
    }else{
        sum=sum/2;
    }
    ll dp[n+1][sum+1];
    ll i,j;

    for(i=0;i<=n-1;i++){            // We have fixed n in one set to avoid the counting of double sets
        for(j=0;j<=sum;j++){        // For small numbers we can also count double sets and finally divide it by 2 but in this when we take modulo then it will not work
            if(j==0){
                dp[i][j]=1;
            }else if(i==0){
                dp[i][j]=0;
            }else{
                dp[i][j]=dp[i-1][j];
                if(j>=i){
                    dp[i][j]+=dp[i-1][j-i];
                    dp[i][j]%=MOD;
                }
            }
        }
    }

    cout<<dp[n-1][sum];




    return 0;
}
