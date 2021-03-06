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

ll sub[200005];     // It stores all the childs of the given node i
ll ans[200005];
ll n;


void fillSub(ll child, ll par){
    ll temp=0;
    for(auto c: adj[child]){
        if(c!=par){
            fillSub(c,child);
            temp+=1+sub[c];
        }
    }

    sub[child]=temp;
}

ll compute(ll child, ll par){
    ll temp=0;
    for(auto c: adj[child]){
        if(c!=par){
            temp+=1+compute(c,child)+sub[c];
        }
    }

    return temp;
}

void solve(ll child, ll par, ll par_ans){
    ans[child]=par_ans-sub[child]+(n-sub[child]-2);     // Only some nodes who are the sub of the current nodes will become closer 1 unit
                                                        // Rest nodes (execept its self and its parent) will become 1 unit far away so calculating answer accordingly. 
    for(auto c: adj[child]){
        if(c!=par){
            solve(c,child,ans[child]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;

    ll i;
    ll a,b;

    for(i=1;i<=n-1;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    fillSub(1,0);

    ans[1]=compute(1,0); // Calculate the answer for node 1 using brute force

    for(auto c: adj[1]){
        solve(c,1,ans[1]);  // Just pass the answer of the parent to its child for computataion
    }

    for(i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
