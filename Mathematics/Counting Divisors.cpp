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

ll divisors[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll i,j;
    for(i=2;i<=1000000;i++){
        if(divisors[i]==0){
            for(j=i;j<=1000000;j+=i){
                divisors[j]=i;
            }
        }
    }
    
    ll n;
    cin>>n;

    while(n--){
        ll x;
        cin>>x;

        ll ans=1;
        
        while(x!=1){
            ll prime = divisors[x];
            ll count=0;
            while(x%prime==0){
                count++;
                x/=prime;
            }              
            ans*=(count+1);
        }

        cout<<ans<<endl;
    }

    return 0;
}
