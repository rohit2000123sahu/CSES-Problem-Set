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

vpl vect;

void solve(ll n, ll from , ll temp, ll to){
    if(n==1){
        vect.pb(mp(from,to));
        return;
    }
    solve(n-1,from,to,temp);
    vect.pb(mp(from,to));
    solve(n-1,temp,from,to);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    solve(n,1,2,3);

    cout<<vect.size()<<endl;

    for(auto c: vect){
        cout<<c.first<<" "<<c.second<<endl;
    }

    return 0;
}
