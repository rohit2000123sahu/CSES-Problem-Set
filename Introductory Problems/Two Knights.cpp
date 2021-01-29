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

    ll i;
    ll total_ways,a,b,ans;

    for(i=1;i<=n;i++){
        total_ways=((i*i)*(i*i-1))/2;
        a=2*(i-1)*(i-2);            //Consider a 2*3 rectangle
        b=2*(i-2)*(i-1);            //Consider a 3*2 rectangle

        ans=total_ways-a-b;
        cout<<ans<<"\n";
    }

    return 0;
}
