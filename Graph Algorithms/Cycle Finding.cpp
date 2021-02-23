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
  
struct tunnel{
    ll src;
    ll dest;
    ll weight;
};
 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
 
    ll u,v,weight,i,j;
    ll relaxant[n+1];       // Storing the relaxant of the current node
 
    tunnel edges[m];
    i=0;
    while(i<m){
        cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
        i++;
    }
 
    ll dist[n+1];
 
    for(i=0;i<=n;i++){      // It is because to handle the disconnected components.
        dist[i]=0;
    }

    ll x=-1;
 
    for(i=1;i<=n;i++){
        x=-1;
        for(j=0;j<m;j++){
            u=edges[j].src;
            v=edges[j].dest;
            weight=edges[j].weight;
            if(dist[u]+weight<dist[v]){
                dist[v]=weight+dist[u];
                relaxant[v]=u;            //Storing the relaxant
                x=u;
            }
            dist[v]=max(dist[v],(ll)NINF);
        }
    }


    if(x==-1){                    // In the nth cycle if it got changes then the graph contains the negative edge cycle
        cout<<"NO"<<endl;
    }else{
        for(i=1;i<=n;i++){
            x=relaxant[x];      // As the edges are not in the specfic order and we have done the nth iteration completly therefore we need to goback nth times to find the node 
        }                       // of the negative cycle

        cout<<"YES"<<endl;

        vl cycle;

        ll v=x;

        while(1){
            cycle.pb(v);
            if(v==x && cycle.size()>1){   // Storing the cycle
                break;
            }
            v=relaxant[v];
        }

        reverse(all(cycle));            // Reversing the cycle and printing it

        for(auto c: cycle){
            cout<<c<<" ";
        }

    } 
    
    return 0;
}
