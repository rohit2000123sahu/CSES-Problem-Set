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

    ll a[n],i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    ll j;
    set< ll > s;

    for(i=0;i<n;i++){
        vl vect;
        for(auto c: s){
            vect.pb(a[i]+c);
        }
        vect.pb(a[i]);
        for(auto c:vect){
            s.insert(c);
        }
    }

    cout<<s.size()<<endl;

    for(auto c: s){
        cout<<c<<" ";
    }



    return 0;
}
