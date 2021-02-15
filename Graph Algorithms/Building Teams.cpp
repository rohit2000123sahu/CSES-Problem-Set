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
ll team[100005];

bool dfs(ll i, ll value){
    visited[i]=true;
    team[i]=value;

    for(auto c: adj[i]){
        if(!visited[c]){
            if(dfs(c,(value+1)%2)==false){
                return false;
            }
        }else if(team[c]==value){
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m,a,b;
    cin>>n>>m;

    ll i;

    memset(team,-1,sizeof(team));
    memset(visited,false,sizeof(visited));

    while(m--){
        cin>>a>>b;
        adj[b].pb(a);
        adj[a].pb(b);
    }

    bool ans=true;

    for(i=1;i<=n;i++){
        if(!visited[i]){
            ans=ans & dfs(i,0);
            if(ans==false){
                break;
            }
        }
    }

    if(ans==false){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        for(i=1;i<=n;i++){
            cout<<team[i]+1<<" ";
        }
    }

    return 0;
}
