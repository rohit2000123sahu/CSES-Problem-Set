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

    ll i,a[n];

    for(i=0;i<n;i++){
        cin>>a[i];
    }

    vpl vect;

    for(i=0;i<n;i++){
        if(vect.size()==0){
            cout<<0<<" ";
            vect.pb(mp(a[i],i));
        }else{
            while(vect.size()>0 && vect.back().first>=a[i]){
                vect.pop_back();
            }
            if(vect.size()==0){
                cout<<0<<" ";
                vect.pb(mp(a[i],i));
            }else{
                cout<<vect.back().second+1<<" ";
                vect.pb(mp(a[i],i));
            }

        }
    }

    return 0;
}
