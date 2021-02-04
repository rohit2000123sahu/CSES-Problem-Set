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
    
    ll n;
    cin>>n;
 
    vpl arr(n),dep(n);
 
    ll i,j;
    for(i=0;i<n;i++){
        cin>>arr[i].first>>dep[i].first;
        arr[i].second=dep[i].second=i;
    }
 
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());


    i=0;
    j=0;
 
    ll ans=0;
    ll count=0;
    ll rooms[n];

    memset(rooms,0,sizeof(rooms));
    priority_queue < ll ,vector< ll > , greater< ll > > vacant;
 
    while(i<n && j<n){
        if(arr[i].F<=dep[j].F){
            count++;
            if(vacant.size()==0){
                rooms[arr[i].S]=count;
            }else{
                rooms[arr[i].S]=vacant.top();
                vacant.pop();
            }
            i++;
        }else{
            count--;
            vacant.push(rooms[dep[j].S]);
            j++;
        }
        ans=max(ans,count);
    }
 
    cout<<ans<<endl;
 
    for(auto c: rooms){
        cout<<c<<" ";
    }
       
 
 
 
 
    return 0;
}
