// Always use BFS for finding the single source shortest path algorithm

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m,a,b;
    cin>>n>>m;

    vl adj[n+1];

    bool visited[n+1];
    ll dist[n+1];
    ll parent[n+1];       // For printing the answer

    memset(dist,-1,sizeof(dist));
    memset(parent,-1,sizeof(parent));
    memset(visited,false,sizeof(visited));

    vl ans;

    while(m--){
        cin>>a>>b;
        adj[b].pb(a);
        adj[a].pb(b);
    }

    queue< ll > q;

    q.push(1);
    visited[1]=true;
    dist[1]=0;

    while(!q.empty()){
        ll temp=q.front();
        q.pop();
        for(auto c: adj[temp]){
            if(!visited[c]){
                q.push(c);
                visited[c]=true;
                dist[c]=1+dist[temp];
                parent[c]=temp;
            }
        }
    }

    if(dist[n]==-1){
        cout<<"IMPOSSIBLE"<<endl;
        exit(0);
    }

    cout<<1+dist[n]<<endl;

    stack< ll > route;
    ll temp=n;

    while(temp!=-1){
        route.push(temp);
        temp=parent[temp];
    }

    while(!route.empty()){
        temp=route.top();
        route.pop();
        cout<<temp<<" ";
    }

    return 0;
}
