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

    vpl vect;

    ll t1,t2,i;

    for(i=0;i<n;i++){
        cin>>t1>>t2;
        vect.pb(mp(t2,t1));
    }

    sort(vect.begin(),vect.end());

    ll finish_time=0;
    ll ans=0;

    for(auto c: vect){
        if(c.second>=finish_time){
            ans++;
            finish_time=c.first;
        }
    }

    cout<<ans<<endl;



    return 0;
}
