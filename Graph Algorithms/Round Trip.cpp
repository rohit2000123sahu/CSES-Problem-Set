//Simple ccycle detection and printing it
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
ll parent[100005];
ll start,finish;

bool dfs(ll i, ll par){
    visited[i]=true;
    parent[i]=par;

    for(auto c: adj[i]){
        if(!visited[c]){
            if(dfs(c,i)){
                return true;
            }
        }else if(c!=par){
            start=i;
            finish=c;
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m,a,b;
    cin>>n>>m;

    ll i;
    start=-1;
    finish=-1;

    memset(parent,-1,sizeof(parent));
    memset(visited,false,sizeof(visited));

    while(m--){
        cin>>a>>b;
        adj[b].pb(a);
        adj[a].pb(b);
    }

    for(i=1;i<=n;i++){
        if(!visited[i]){
           if(dfs(i,-1)){
               break;
           }
        }
    }

    if(start==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        vl ans;
        ll  temp=start;

        ans.pb(finish);

        while(temp!=finish){
            ans.pb(temp);
            temp=parent[temp];
        }

        ans.pb(finish);

        cout<<ans.size()<<endl;

        for(auto c: ans){
            cout<<c<<" ";
        }

    }

    return 0;
}
