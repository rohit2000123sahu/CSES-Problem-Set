// We have used the kruskal's algorithm here
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

ll parent[100005];
ll tsize[100005];

ll find(ll x){
    if(x==parent[x]){
        return x;
    }
    parent[x]=find(parent[x]);
    return parent[x];
}

bool same(ll a, ll b){
    a=find(a);
    b=find(b);
    return a==b;
}

void unite(ll a, ll b){
    a=find(a);
    b=find(b);
    if(tsize[a]<tsize[b]){
        swap(a,b);
    }

    tsize[a]+=tsize[b];
    parent[b]=a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;

    priority_queue < ppl , vector< ppl > , greater< ppl > > q;
    
    ll a,b,cost,i;
    ll ans=0;
    while(m--){
        cin>>a>>b>>cost;
        q.push(mp(cost,mp(a,b)));
    }

    for(i=1;i<=n;i++){
        parent[i]=i;
        tsize[i]=1;
    }

    while(!q.empty()){
        ppl curr=q.top();
        q.pop();

        cost=curr.F;
        a=curr.S.F;
        b=curr.S.S;

        if(!same(a,b)){
            ans+=cost;
            unite(a,b);
        }
    }

    bool flag=false;

    for(i=1;i<=n;i++){
        if(tsize[i]==n){
            flag=true;
            break;
        }
    }

    if(flag){
        cout<<ans<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
