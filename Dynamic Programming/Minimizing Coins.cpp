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
        
        ll n,x;
        cin>>n>>x;

        ll c[n];
        ll i,j;

        for(i=0;i<n;i++){
            cin>>c[i];
        }

        ll dp[x+1];

        dp[0]=0;

        for(i=1;i<=x;i++){
            dp[i]=LONG_MAX;
            for(j=0;j<n;j++){
                if(i-c[j]>=0 && dp[i-c[j]]!=LONG_MAX){
                    dp[i]=min(dp[i],1+dp[i-c[j]]);
                }
            }
        }

        if(dp[x]==LONG_MAX){
            dp[x]=-1;
        }

        cout<<dp[x];

        return 0;
    }
