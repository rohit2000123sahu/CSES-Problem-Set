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
bool visited[100005];

void dfs(ll i){
    visited[i]=true;
    for(auto c: adj[i]){
        if(!visited[c]){
            dfs(c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m,i,a,b;
    cin>>n>>m;

    vl ans;

    memset(visited,false,sizeof(visited));

    while(m--){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for(i=1;i<=n;i++){
        if(!visited[i]){    // Find the connected components
            dfs(i);
            ans.pb(i);
        }
    }

    ll as=ans.size()-1;

    cout<<as<<endl;

    for(i=0;i<as;i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }

    return 0;
}
