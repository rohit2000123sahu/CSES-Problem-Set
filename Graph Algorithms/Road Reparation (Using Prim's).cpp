// This problem is also solved using the Kruksal's Algorithm already
// In this we have used the prism algorithm to solve the same problem
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
typedef pair< ll , pl > ppl;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;

    vpl adj[n+1];

    ll i;

    ll u,v,weight;

    for(i=0;i<m;i++){
        cin>>u>>v>>weight;
        adj[u].pb(mp(weight,v));
        adj[v].pb(mp(weight,u));      // Creating the adjacency matrix
    }

    bool visited[n+1];

    for(i=1;i<=n;i++){
        visited[i]=false;
    }

    priority_queue < pl , vector< pl > , greater< pl > > q;
    visited[1]=true;
    i=1;                          // We have taken the start node as 1 as marking it as visited
    ll ans=0;                     // We can choose any node as the starting vertex.

    for(auto c: adj[i]){
        q.push({c.F,c.S});        // Pushing all the possible adjacent nodes in the queue
    }

    while(!q.empty()){

        pl curr = q.top();        // Get the minimum from priority queue
        q.pop();

        weight = curr.F;
        v=curr.S;

        if(visited[v]){         // If it is already been processed then continue
            continue;
        }

        visited[v]=true;      // Else make it true
        ans+=weight;
        i=v;

        for(auto c: adj[i]){    // Now push its all adjacent in the priority queue 
            q.push({c.F,c.S});
        }
    }

    for(i=1;i<=n;i++){
        if(!visited[i]){      //If it is not possible to visit all the nodes then print the impossible as the answer and exit the program
            cout<<"IMPOSSIBLE"<<endl; 
            exit(0);
        }
    }

    cout<<ans<<endl;        // Else print the answer

    return 0;
}
