// Just find the number of strongly connected components

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

vl adj[100005];
vl rev[100005];
ll ans[100005];
bool visited[100005];

stack< ll > s;

void dfs(ll i){
    visited[i]=true;
    for(auto c: adj[i]){
        if(!visited[c]){
            dfs(c);
        }
    }
    s.push(i);
}

void revDFS(ll i, ll k){
    visited[i]=true;
    for(auto c: rev[i]){
        if(!visited[c]){
            revDFS(c,k);
        }
    }
    ans[i]=k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,m;
    cin>>n>>m;

    ll i;
    ll u,v;

    for(i=0;i<m;i++){
        cin>>u>>v;
        adj[u].pb(v);
        rev[v].pb(u);
    }

    memset(visited,false,sizeof(visited));

    for(i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    memset(visited,false,sizeof(visited));

    ll k=0;

    while(!s.empty()){
        ll curr=s.top();
        s.pop();
        if(visited[curr]){
            continue;
        }
        k++;
        revDFS(curr,k);
    }

    cout<<k<<endl;

    for(i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    
    cout<<endl;

    return 0;
}
