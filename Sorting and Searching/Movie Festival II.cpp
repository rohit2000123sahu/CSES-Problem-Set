// In this question if we try to use priority queue then it will not give us optimal ans.
// Hence we should use the multiset for optimal answer.

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
    
    ll n,k,i;
    cin>>n>>k;

    multiset< ll > m;

    for(i=0;i<k;i++){
        m.insert(0);
    }

    vpl vect;        // Finish time and start time in pair
    ll start,finish;  

    for(i=0;i<n;i++){
        cin>>start>>finish;
        vect.pb(mp(finish,start));
    }

    sort(vect.begin(),vect.end());

    ll ans=0;
    
    for(i=0;i<n;i++){
        auto temp=m.upper_bound(vect[i].S);
        if(temp!=m.begin()){
            ans++;
            temp--;
            m.erase(temp);
            m.insert(vect[i].F);
        }
    }

    cout<<ans<<endl;

    return 0;
}
