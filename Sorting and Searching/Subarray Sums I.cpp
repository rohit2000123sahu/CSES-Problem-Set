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

    ll a[n],i,j;
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    ll sum=0,ans=0;
    i=j=0;
    while(i<n && j<n){
        if(sum==target){
            sum=sum-a[i];
            sum+=a[j];
            i++;
            j++;
            ans++;
        }else if(sum>target){
            sum=sum-a[i];
            i++;
        }else{
            sum+=a[j];
            j++;
        }

        if(i>j){
            j=i;
        }
    }

    while(i<n){
        if(sum==target){
            ans++;
        }
        sum=sum-a[i];
        i++;
    }



    cout<<ans<<endl;




    return 0;
}
