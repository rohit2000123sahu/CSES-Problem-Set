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
    
    ll n,target;
    cin>>n>>target;

    ll i,j,k;
    vpl a(n);

    for(i=0;i<n;i++){
        cin>>a[i].F;
        a[i].S=i+1;
    }

    sort(a.begin(),a.end());
    ll temp;
    
    for(k=0;k<n-2;k++){
        i=k+1;
        j=n-1;
        temp=target-a[k].F;
        while(i<j){
            if(a[i].F+a[j].F==temp){
                cout<<a[k].S<<" "<<a[i].S<<" "<<a[j].S<<endl;
                exit(0);
            }else if(a[i].F+a[j].F>temp){
                j--;
            }else{
                i++;
            }
        }
    }

    cout<<"IMPOSSIBLE";

    return 0;
}
