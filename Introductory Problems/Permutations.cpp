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
typedef vector< ll > vl;
typedef pair< ll , ll > pl;
typedef unordered_map< ll, ll > uml;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;
 
    if(n==2||n==3){           //Base Cases
        cout<<"NO SOLUTION"<<endl;
        exit(0);
    }
 
    vl vect;
    ll i;
 
    for(i=2;i<=n;i+=2){
        vect.pb(i);
    }
 
    for(i=1;i<=n;i+=2){
        vect.pb(i);
    }
 
    for(auto c: vect){
        cout<<c<<" ";
    }
    cout<<endl;
 
    return 0;
}
