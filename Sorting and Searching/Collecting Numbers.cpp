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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,i,temp;
    cin>>n;
    vpl vect;

    for(i=0;i<n;i++){
        cin>>temp;
        vect.pb(mp(temp,i));
    }

    sort(vect.begin(),vect.end());          // Sorting on the based of the values
    
    ll ans=0;

    i=0;
    while(i<n){
        i++;
        while(i<n && vect[i].second>vect[i-1].second){          // Collecting the maximum number we could collect in one go
            i++;
        }
        ans++;
    }

    cout<<ans<<endl;

    return 0;
}
