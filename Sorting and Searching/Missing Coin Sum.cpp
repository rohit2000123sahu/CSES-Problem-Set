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

ll solve(ll a[] , ll n){
    ll ans=1;               //It is storing the value that we cannot create
    ll i;
    for(i=0;i<n;i++){
        if(ans<a[i]){       // If we have found a number that is greater than ans then ans is our final answer and we need to go out  of loop.
            break;
        }else{
            ans+=a[i];      // Else we would add it because we know that we can create all the sums between 1 to ans-1 hence we can get sum upto 1 to ans+a[i]-1;
        }
    }

    return ans;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    ll i;
    ll a[n];

    for(i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);


    cout<<solve(a,n);



    return 0;
}
