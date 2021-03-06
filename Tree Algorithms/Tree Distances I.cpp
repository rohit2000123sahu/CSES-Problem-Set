//Time complexity O(n)

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

vl adj[200005];
ll ans[200005];
ll dep[200005];

void calcDep(ll child, ll par){     //Function for calculating depth
    ll temp=0;

    for(auto c: adj[child]){
        if(c!=par){
            calcDep(c,child);
            temp=max(temp,1+dep[c]);
        }
    }

    dep[child]=temp;
}

void solve(ll child, ll par, ll par_ans){   // Here the par_ans the maximum distance for child if we do not consider the given parent child node
    vl prefix,suffix;

    // For that child we will calculate for prefix and suffix array.
    // These array contains thee maximum length for a[0].. a[i-1] and a[i+1]..a[n] where a[0]..a[n] all are children of child

    for(auto c: adj[child]){
        if(c!=par){
            prefix.pb(dep[c]);
            suffix.pb(dep[c]);
        }
    }

    ll i;
    ll n=prefix.size();

    for(i=1;i<n;i++){
        prefix[i]=max(prefix[i],prefix[i-1]);
    }

    for(i=n-2;i>=0;i--){
        suffix[i]=max(suffix[i],suffix[i+1]);
    }
    
    ll count=0;

    for(auto c: adj[child]){
        if(c!=par){
            ll temp1=LONG_MIN;
            if(count!=0){
                temp1=prefix[count-1];
            }

            ll temp2=LONG_MIN;
            if(count!=n-1){
                temp2=suffix[count+1];
            }

            ll partial = 1+max(par_ans,max(temp1,temp2)); // Now for each children we will calculate the max answer without considering that child and grandchild relation 

            solve(c,child,partial); // Solve recursively for it
            count++;
            
        }
    }

    ans[child]=1+max(par_ans,(prefix.empty()?-1:prefix.back()));    // We have already calculated the maximum answer without considering that edge and we will compare it by maxmimum depth in the sub tree to find the answer


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    ll i;
    ll a,b;

    for(i=1;i<=n-1;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    memset(dep,0,sizeof(dep));

    calcDep(1,0);       // Calculating the mnaximum depth for each node

    solve(1,0,-1);      // Calculating the answer for each node

    for(i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

    

    return 0;
}
