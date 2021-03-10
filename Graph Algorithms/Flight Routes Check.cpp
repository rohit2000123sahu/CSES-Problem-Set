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
  
vl adj[100005];         //Original Adjacency List
vl revAdj[100005];      // Reverse Adjacency List
bool visited[100005];

void dfs(ll i){           // DFS on Adjacency List
    visited[i]=true;
    for(auto c: adj[i]){
        if(!visited[c]){
            dfs(c);
        }
    }
}

void revDfs(ll i){        // DFS on Reverse Adjacency List
    visited[i]=true;
    for(auto c: revAdj[i]){
        if(!visited[c]){
            revDfs(c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;

    ll i;

    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        revAdj[b].pb(a);
    }

    memset(visited,false,sizeof(visited));

    dfs(1);

    for(i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i<<endl;
            exit(0);
        }
    }

    memset(visited,false,sizeof(visited));

    revDfs(1);

    for(i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<1<<endl;
            exit(0);
        }
    }

    cout<<"YES"<<endl;
   
    return 0;
}
