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
    
    ll n,k;
    cin>>n>>k;

    ll a[n];
    ll i,j;

    for(i=0;i<n;i++){
        cin>>a[i];
    }

    ll ans=0;

    i=0;                // Representing the start index in subarray
    j=1;                // Representing the end index in subarray
    ans=1;
    ml myMap;           // To store the lastest index of elements
    myMap[a[0]]=0;      
    ll distinct=1;      // To store the number of distinct elements

    while(j<n){
        if(myMap.find(a[j])==myMap.end()){  // If element was not present then we will insert it and update distinct
            distinct++;
            myMap[a[j]]=j;
        }else{
            myMap[a[j]]=j;          // Else just update its index value in map
        }

        while(distinct>k){          // If the distinct value is greater than permissible then reduce the subarray size
            if(i==myMap[a[i]]){     // If the current element is the last element of that value in the subarray then on removing it the distinct will reduce by 1
                myMap.erase(myMap.find(a[i]));
                distinct--;
            }
            i++;
        }

        ans+=j-i+1;
        j++;

    }
    
    cout<<ans<<endl;

    return 0;
}
