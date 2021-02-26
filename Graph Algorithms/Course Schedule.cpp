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
ll indegree[100005];
queue< ll > q;
vl ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;

    ll u,v;

    memset(indegree,0,sizeof(indegree));

    while(m--){
        cin>>u>>v;
        adj[u].pb(v);
        indegree[v]++;
    }

    ll i;
    for(i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        ll curr = q.front();
        q.pop();

        ans.pb(curr);

        for(auto c: adj[curr]){
            indegree[c]--;
            if(indegree[c]==0){
                q.push(c);
            }
        }
    }

    if(ans.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
        exit(0);
    }

    for(auto c: ans){
        cout<<c<<" ";
    }



    return 0;
}
