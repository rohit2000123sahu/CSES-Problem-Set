#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S secondP
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
bool rec[100005];
ll parent[100005];

ll finish=-1;
ll start=-1;

bool dfs(ll i, ll par){
    visited[i]=true;
    rec[i]=true;
    parent[i]=par;

    for(auto c: adj[i]){
        if(!visited[c]){
            if(dfs(c,i)){
                return true;
            }
        }else if(rec[c]){
            start=c;
            finish=i;
            return true;
        }
    }

    rec[i]=false;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;

    ll u,v;

    ll i;

    for(i=0;i<m;i++){
        cin>>u>>v;
        adj[u].pb(v);
    }

    memset(visited,false,sizeof(visited));
    memset(rec,false,sizeof(rec));

    bool cycle=false;

    for(i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(i,-1)){
                cycle=true;
                break;
            }
        }
    }

    if(!cycle){
        cout<<"IMPOSSIBLE"<<endl;
        exit(0);
    }

    vl ans;
    ll temp=finish;
    while(temp!=start){
        ans.pb(temp);
        temp=parent[temp];
    }

    ans.pb(start);

    ans.push_back(finish);

    reverse(ans.begin(),ans.end());

    cout<<ans.size()<<endl;

    for(auto c: ans){
        cout<<c<<" ";
    }

    return 0;
}
