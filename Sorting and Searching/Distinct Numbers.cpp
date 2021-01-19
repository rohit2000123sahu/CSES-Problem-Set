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
 
 
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        ll n,temp;
        cin>>n;
 
        ll i,a[n];
 
        for(i=0;i<n;i++){
            cin>>a[i];
        }
 
        sort(a,a+n);
 
        ll count=1;
 
        for(i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                count++;
            }
        }
 
        cout<<count<<"\n";

        return 0;
    }
