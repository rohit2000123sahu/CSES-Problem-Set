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

    ll power(ll a, ll b){
        if(b==1){
            return a;
        }
        if(b==0){
            return 1;
        }

        ll temp = power(a,b/2);

        if(b%2==0){
            return (temp*temp)%MOD;
        }else{
            return (((temp*temp)%MOD)*a)%MOD;
        }
    }


    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        ll n;
        cin>>n;

        ll ans = power(2,n);
        cout<<ans<<"\n";




        return 0;
    }
