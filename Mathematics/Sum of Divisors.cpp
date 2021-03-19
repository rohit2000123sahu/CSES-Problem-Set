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
    cout.tie(NULL);
    
    ll n;
    cin>>n;

    ll i,j;

    ll ans=0;

    i=1;
    while(i<=n){
        ll q=n/i;       // Here we are calculating the quotient
        j=n/q+1;        // Here we are calculating which number is having the the quotient just greater than previous one

        // now we want the summation of i to j-1;
        // It is ((j+i-1)*(j-i))/2;

        // We can not calcalate then independently and substract them because moudules operator doesn't work on division
        // And it contains division by 2;
        // Hence we need to calculate it using the formula
        // We can also generate this formula easily.

        ll x=j+i-1;
        ll y=j-i;

        if(x%2==0){
            x=x/2;
        }else{
            y=y/2;
        }

        x=x%MOD;
        y=y%MOD;

        ans+=q%MOD*x%MOD*y%MOD;
        ans=ans%MOD;
        i=j;
    }

    cout<<ans<<endl;

    return 0;
}
