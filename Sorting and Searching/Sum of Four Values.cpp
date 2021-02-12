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
    
    ll n,sum;
    cin>>n>>sum;

    ll a[n];
    ll i,j;

    for(i=0;i<n;i++){
        cin>>a[i];
    }

    map< ll , pl > umap;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            umap[a[i]+a[j]]=mp(i,j);
        }
    } 

    bool flag=true;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            ll target = sum-a[i]-a[j];
            if(umap.find(target)!=umap.end()){
                if(i!=umap[target].F && i!=umap[target].S && j!=umap[target].F && j!= umap[target].S){
                    cout<<i+1<<" "<<j+1<<" "<<umap[target].F+1<<" "<<umap[target].S+1<<endl;
                    flag=false;
                    break;
                }
            }
        }
        if(flag==false){
            break;
        }
    }

    if(flag){
        cout<<"IMPOSSIBLE"<<endl;
    }


    return 0;
}
