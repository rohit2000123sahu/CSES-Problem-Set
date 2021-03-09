// This problem is an extension of previous problem so please solve the previous problem first
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

ll parent[100005];
ll tsize[100005];
multiset< ll > mset;

ll find (ll a){
    if(a==parent[a]){
        return a;
    }
    parent[a]=find(parent[a]);
    return parent[a];
}

ll same(ll a, ll b){
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
    mset.erase(mset.find(tsize[a]));
    mset.erase(mset.find(tsize[b]));

    parent[b]=a;
    tsize[a]+=tsize[b];
    mset.insert(tsize[a]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;

    ll m,i;
    cin>>m;

    for(i=1;i<=n;i++){
        parent[i]=i;
        tsize[i]=1;
        mset.insert(1);
    }

    for(i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;

        if(!same(a,b)){
            unite(a,b);
        }
        cout<<mset.size()<<" "<<*mset.rbegin()<<endl;
    }

    return 0;
}
