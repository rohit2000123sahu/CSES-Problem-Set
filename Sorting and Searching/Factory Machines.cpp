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
    
    ll n,t,i;
    cin>>n>>t;

    ll capacity[n];
    for(i=0;i<n;i++){
        cin>>capacity[i];
    }
    
    ll low=1,mid=0,temp;
    ll high=1e18;

    while(low<high){
        mid=low+(high-low)/2;
        temp=0;
        for(i=0;i<n;i++){
            temp+=min(mid/capacity[i],(ll)1e9);     // Because to prevent it from out of bounds;
        }
        if(temp>=t){
            high=mid;
        }else{
            low=mid+1;
        }
    }

    cout<<low;



    return 0;
}
