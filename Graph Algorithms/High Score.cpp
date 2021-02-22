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
#define INF 1e17
#define NINF -1e17
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;
typedef map< ll, ll > ml;

vl adj[2505];

struct tunnel{
    ll src;
    ll dest;
    ll weight;
};

void dfs(ll i, bool visited[]){
    visited[i]=true;
    for(auto c: adj[i]){
        if(!visited[c]){
            dfs(c,visited);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;

    ll u,v,weight,i,j;

    tunnel edges[m];
    i=0;
    while(i<m){
        cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
        adj[edges[i].src].pb(edges[i].dest);
        edges[i].weight=-1*edges[i].weight;   // Making the weight negatives so on finding the minimum we got the maximum answer
        i++;
    }

    ll dist[n+1];

    for(i=0;i<=n;i++){
        dist[i]=INF;
    }

    dist[1]=0;

    for(i=1;i<n;i++){               //Finding the minimum distances
        for(j=0;j<m;j++){
            u=edges[j].src;
            v=edges[j].dest;
            weight=edges[j].weight;
            if(dist[u]==INF){
                continue;
            }
            if(dist[u]+weight<dist[v]){
                dist[v]=weight+dist[u];
            }

            dist[v]=max(dist[v],(ll)NINF);
        }
    }

    bool visited[n+1];
    memset(visited, false,sizeof(visited));

    for(j=0;j<m;j++){     // IF there is the negative cycle then we need to find whether we could reach the destination form that node if yes then it would be infinte distance.  
        u=edges[j].src;
        v=edges[j].dest;
        weight=edges[j].weight;
        if(dist[u]==INF){
            continue;
        }
        if(dist[u]+weight<dist[v]){
            dist[v]=weight+dist[u];
            dfs(u,visited);     // Hence using the dfs for it.
        }

        dist[v]=max(dist[v],(ll)NINF);
    }

    if(visited[n]){       // If we could reach the destination from that negative edge cycle then in this case answer is INFINITE
        cout<<-1<<endl;
    }else{
        cout<<-1*dist[n]<<endl;
    }

    return 0;
}
