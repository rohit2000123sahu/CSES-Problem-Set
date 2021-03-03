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
 
    vpl arr(n),dep(n);    // Pair for storing the values as well as index
 
    ll i,j;
    for(i=0;i<n;i++){
        cin>>arr[i].first>>dep[i].first;
        arr[i].second=dep[i].second=i;   // Storing the index 
    }
 
    sort(arr.begin(),arr.end());         // Sort them
    sort(dep.begin(),dep.end());


    i=0;
    j=0;
 
    ll ans=0;
    ll count=0;
    ll rooms[n];      // For storing the rooms allocated to the customers

    memset(rooms,0,sizeof(rooms));
    priority_queue < ll ,vector< ll > , greater< ll > > vacant;  // This will contains the rooms that are vacant 
 
    while(i<n && j<n){
        if(arr[i].F<=dep[j].F){     
            count++;
            if(vacant.size()==0){         // If no rooms are vacant then we need to give a new room to the customer
                rooms[arr[i].S]=count;
            }else{
                rooms[arr[i].S]=vacant.top();  // If some rooms are vacant already then we can give these rooms to the customer
                vacant.pop();
            }
            i++;
        }else{
            count--;
            vacant.push(rooms[dep[j].S]);  // If some customer leaves the room then push the room in to the vacant list
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
