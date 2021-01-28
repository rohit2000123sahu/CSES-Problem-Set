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
    
    ll n,target;
    cin>>n>>target;

    vpl a;
    ll i,temp;

    for(i=0;i<n;i++){
        cin>>temp;
        a.pb({temp,i+1});
    }

    sort(a.begin(),a.end());

    ll j;
    i=0;
    j=n-1;

    bool done=false;

    while(i<j){
        if(a[i].first+a[j].first==target){
            done=true;
            cout<<a[i].second<<" "<<a[j].second;
            break;
        }else if(a[i].first+a[j].first>target){
            j--;
        }else{
            i++;
        }
    }

    if(!done){
        cout<<"IMPOSSIBLE";
    }




    return 0;
}
