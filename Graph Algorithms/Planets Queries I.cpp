// In this problem we have used the concept of binary lifting so please go through this concept before moving to this problem.

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

ll adj[200005];
ll up[200005][31];
ll n;

void fillUp(){              // For filling the up matrix 
    ll i,j;                 // Note that we should fill this matrix in iterative order.
    for(i=1;i<=n;i++){      // If we try recurive method then we will get the TLE on some test cases.
        up[i][0]=adj[i];
    }

    for(j=1;j<=30;j++){
        for(i=1;i<=n;i++){
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
}

ll solve(ll x, ll k){     // This is for solving the specific query.
    if(k==0){
        return x;
    }

    ll i;
    ll temp;
    temp=1<<30;
    for(i=30;i>=0;i--){
        if(k>=temp){
            x=up[x][i];
            k=k-temp;
            if(k==0){
                return x;
            }
        }
        temp=temp/2;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll q;
    cin>>n>>q;

    ll i;

    memset(up,-1,sizeof(up));

    for(i=1;i<=n;i++){
        cin>>adj[i];
    }

    fillUp();

    while(q--){
        ll x,k;
        cin>>x>>k;

        cout<<solve(x,k)<<endl;

    }
    return 0;
}
