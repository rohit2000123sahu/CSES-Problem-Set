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
#define INF 1e18
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
typedef vector< pl > vpl;
typedef pair< ll , pl > ppl;
typedef map< ll, ll > ml;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;

    vpl adj[n+1];       //Adjacency list
    ll a,b,c,i;

    while(m--){
        cin>>a>>b>>c;
        adj[a].pb(mp(c,b));
    }

    ll dist[n+1];       // Distance 
    ll distCou[n+1];     // With the use of the coupon

    for(i=1;i<=n;i++){
        dist[i]=INF;
        distCou[i]=INF;
    }

    priority_queue< ppl, vector< ppl > , greater< ppl > > q;    // It contains the cost, source node and flag which indicates whehter coupon is used or not 
    bool visited[n+1];
    bool visitedCou[n+1];

    memset(visited,false,sizeof(visited));
    memset(visitedCou,false,sizeof(visitedCou));

    q.push(mp(0,mp(1,0)));        // Inserting the initial distance, source node and flag=0 which means coupon has not been used yet.
    dist[1]=0;
    distCou[1]=0;

    while(!q.empty()){
        ppl curr=q.top();
        q.pop();

        ll u =curr.S.F;       // Here u is the source node

        ll flag=curr.S.S;

        if(flag==1){
            if(visitedCou[u]){
                continue;
            }else{
                visitedCou[u]=true;
            }
            for(auto c: adj[u]){
                ll v=c.S;            // Here v is the destination node
                ll weight=c.F;      // This is the weight of the vertex u to v;
                if(distCou[u]+weight<distCou[v]){
                    distCou[v]=distCou[u]+weight;
                    q.push(mp(distCou[v],mp(v,1)));
                }
            }
        }else{
            if(visited[u]==true){   // It is because if we have inserted in it queue multiple times (Let say on the first time it was (5,x) , second time (4,x) and thrid time(3,x))
                continue;           // On the first time it has been processed with (3,x) then it not needed to be processed again and again because nothing will get updated. Hence just skip it.
            }else{
                visited[u]=true;  
            }
            for(auto c: adj[u]){
                ll v=c.S;            // Here v is the destination node
                ll weight=c.F;      // This is the weight of the vertex u to v;

                if(dist[u]+weight<dist[v]){     // If we do not use our coupon
                    dist[v]=dist[u]+weight;
                    q.push(mp(dist[v],mp(v,0)));
                }
                if(dist[u]+weight/2<distCou[v]){    // If we use our coupon then
                    distCou[v]=dist[u]+weight/2;
                    q.push(mp(dist[v],mp(v,1)));
                }
            }
        }      
    }

    cout<<distCou[n]<<endl;

    return 0;
}
